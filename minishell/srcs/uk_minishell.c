#include "../include/minishell.h"

int	nbr_length(int n)
{
	int	i = 0;

	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	get_cursor_position(int *col, int *rows)
{
	int		a = 0;
	int		i = 1;
	char	buf[255];
	int		ret;
	int		temp;

	write(0, "\033[6n", 4);  //report cursor location
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			if (a == 0)
				*rows = atoi(&buf[i]) - 1;
			else
			{
				temp = atoi(&buf[i]);
				*col = temp - 1;
			}
			a++;
			i += nbr_length(temp) - 1;
		}
		i++;
	}
}

int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	move_cursor_left(int *col, int *row, char *cm)
{
	if (*col == 0)
		return ;
	--(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);

}

void	move_cursor_right(int *col, int *row, char *cm)
{
	++(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);

}

void	delete_end(int *col, int *row, char *cm, char *ce)
{
	--(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);
	tputs(ce, 1, putchar_tc);
}



void			signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\b\b  \b\b\n", 1);
		ft_putstr_fd("$>", 1);
	}
	// if (signo == SIGTERM)
	// {
	// 	exit(0);
	// }
}

t_token			*token_lstlast(t_token *lst)
{
	t_token *new;

	if (!lst)
		return (0);
	new = lst;
	while (new->next)
		new = new->next;
	return (new);
}

void			token_add_back(t_token **tokens, t_token *new)
{
	t_token *lstnew;

	if (!tokens || !new)
		return ;
	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	lstnew = token_lstlast(*tokens);
	lstnew->next = new;
	new->next = NULL;
}

t_token			*new_lst_token(char *line, t_token **tokens, t_var *var)
{
	t_token *new;

	new = (t_token *)malloc(sizeof(t_token) * 1);
	if (!new)
		return (0);
	new->token = ft_substr(line, var->start_pos, var->end_pos);
	new->next = 0;
	return (new);
}

void			add_token_data(char *line, t_var *var, t_token **tokens)
{
	token_add_back(tokens, new_lst_token(line, tokens, var));
}

int					is_in_char(char ch, char *str)
{
	while (*str)
	{
		if (ch == *str)
			return (1);
		str++;
	}
	return (0);
}

void				start_check(char *line, t_var *var, int *i)
{
	while (line[(*i)] == ' ')
	{
		(*i)++;
	}
	var->start_pos = (*i);
}

int				end_check(char *line, t_var *var, int *i)
{
	while (line[*i])
	{
		if (is_in_char(line[*i], ";<>|"))
		{
			var->end_pos = *i;
			return (1);
		}
		(*i)++;
	}
	var->end_pos = *i;
	return (0);
}

void			quote_check(char *line, t_var **var, int i)
{
	while (line[i])
	{
		if (line[i] == 39 || line[i] == 33)
		{

		}
		i++;
	}
}

void			seperate_token(t_token **tokens, int *i, t_var *var)
{
	int idx;
	int space;
	char *temp;
	int	save;

	idx = 0;
	space = 0;
	save = 0;
	while ((*tokens)->token[idx])
	{
		if (space == 0 && (*tokens)->token[idx] == ' ')
		{
			(*tokens)->cmd = ft_substr((*tokens)->token, 0, idx);
			save = idx + 1;
			space = 1;
		}
		// if (space == 1)
		// {
		// 	(*tokens)->argv = ft_substr((*tokens)->token, 0, ft_strlen((*tokens)->token));
		// }
		idx++;
	}
	if (space == 0)
	{
		(*tokens)->cmd = ft_substr((*tokens)->token, 0, idx);
	}
	(*tokens)->argv = ft_substr((*tokens)->token, 0, ft_strlen((*tokens)->token));

}

void			tokenization(char *line, t_token **tokens, t_list **head)
{
	t_var	var;
	int		i;

	i = 0;
	while (line[i])
	{
		start_check(line, &var, &i);
		// quote_check(line, &var, i);
		end_check(line, &var, &i);
		add_token_data(line, &var, tokens);
		i++;
	}
	i = -1;
	t_token *temp;

	temp = *tokens;
	while (temp)
	{
		seperate_token(&temp, &i, &var);
		temp = temp->next;
	}
	free(line);
}

void			parse_minishell(char *line, t_list **head)
{
	t_token		*tokens;


	tokens = 0;
	
	tokenization(line, &tokens, head);
	parsing_data(&tokens, head);
}

int				main(int argc, char *argv[], char *envp[])
{
	char		*line;
	char		*new_line;
	t_list		*head;
	t_list		*history;
	t_list		*temp;
	t_list		*next_temp;
	char		buf[4096];
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;    // noon-canonical input 설정
	term.c_lflag &= ~ECHO;      // 입력 시 터미널에 보이지 않게
	term.c_cc[VMIN] = 1;        // 최소 입력 버퍼 크기
	term.c_cc[VTIME] = 0;       //버퍼 비우는 시간 (timeut)
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	tgetent(NULL, "xterm");
	char *cm = tgetstr("cm", NULL); //cursor motion
	char *ce = tgetstr("ce", NULL); //clear line from cursor
	char *str_temp;
	int row;
	int col;
	int c;
	int flag = 0;
    int delete;
	head = NULL;

	init_list(&head, envp);
	// signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	int i;
	history = (t_list *)malloc(sizeof(t_list) * 1);
	history = NULL;
	ft_putstr_fd("$>", 1);
    int up_flag;
	while (1)
	{
		signal(SIGINT, signal_handler);
		ft_memset(buf, 0, 4096);
		i = 0;
		flag = 0;
		temp = history;
        c = 0;
        up_flag = 0;
		while (read(0, &c, sizeof(c)) > 0)
		{
			get_cursor_position(&col, &row);
			if (c == LEFT_ARROW)
			{
                c = 0;
                if (col > 2)
				    move_cursor_left(&col, &row, cm);
                continue ;
			}
			else if (c == RIGHT_ARROW)
			{
                c = 0;
                if (col < i + 2)
				    move_cursor_right(&col, &row, cm);
                continue ;
			}
			else if (c == BACKSPACE)
			{
                c = 0;
                if (col > 2)
                {
				    delete_end(&col, &row, cm, ce);
                    if (i >= 0)
                    {
                        while (i >= col - 2)
                        {
                            buf[i] = '\0';
                            i--;
                        }
                    }
                }
                if (i <= 0)
                    i = 0;
                continue ;
			}
			else if (c == UP_ARROW)
			{
                printf("why?\n");
                c = 0;
                if (!temp)
                {
                    continue ;
                }
				str_temp = ft_strdup(temp->history);
                if (flag == 0)
                    ft_lstadd_front(&history, new_history(buf));
                ft_memset(buf, 0, 4096);
                ft_strlcpy(buf, str_temp, ft_strlen(str_temp) + 1);
                if (str_temp)
                    free(str_temp);
                i = ft_strlen(buf) - 1;
                if (temp && flag == 0)
                {
                    next_temp = temp->next;
                    temp = history;
                    temp = next_temp;
                }
                tputs(tgoto(cm, 2, row), 1, putchar_tc);
	            tputs(ce, 1, putchar_tc);
                // write(1, &buf, ft_strlen(buf));
                write(0, &buf, ft_strlen(buf));
                up_flag = 1;
                continue ;
			}
			else if (c == DOWN_ARROW)
			{
                c = 0;
                if (!temp)
                {
                    continue ;
                }
                if (temp)
                {
                    next_temp = temp->prev;
                    temp = history;
                    temp = next_temp;
                }
				str_temp = ft_strdup(temp->history);
                ft_memset(buf, 0, 4096);
                ft_strlcpy(buf, str_temp, ft_strlen(str_temp) + 1);
                if (str_temp)
                    free(str_temp);
                i = ft_strlen(buf);
                tputs(tgoto(cm, 2, row), 1, putchar_tc);
	            tputs(ce, 1, putchar_tc);
                write(0, &buf, ft_strlen(buf));
                // write(1, &buf, ft_strlen(buf));
                continue ;
			}
            else
                write(0, &c, 1);
            if (c == 10)
            {
                break ;
            }
			buf[i] = c;
            c = 0;
            i++;
            flag = 0;
		}
		if (ft_strncmp(buf, "save", 4) == 0)
		{
			while (temp)
			{
				printf("in history : %s\n", temp->history);
				temp = temp->next;
			}
			continue ;
		}
		if (c == 4)
			break ;
		if (!*buf)
		{
			ft_putstr_fd("$>", 1);
			continue ;
		}
		ft_lstadd_front(&history, new_history(buf));
		if (ft_strncmp(buf, "exit", 4) == 0)
			exit(0);
		new_line = ft_strdup(buf);
		parse_minishell(new_line, &head);
		ft_putstr_fd("$>", 1);
	}
	return (0);
}
