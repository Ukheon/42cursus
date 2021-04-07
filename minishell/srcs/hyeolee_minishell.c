#include "../include/hyeolee_minishell.h"

void			signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\b\b  \b\b\n", 1);
		ft_putstr_fd("minishell$> ", 1);
	}
	if (signo == SIGTERM)
	{
		exit(0);
	}
}

int					quote_end_check(char *line, int idx, t_var **var)
{
	if (!(*var)->quote || idx == (*var)->quote_idx)
		return (0);
	if ((*var)->quote == line[idx])
	{
		(*var)->quote = 0;
		return (1);
	}
	return (0);
}

int					option_end_check(char *line, int idx, t_var **var)
{
	if ((*var)->prev && idx == (*var)->start_idx)
		return (1);
	if (idx != (*var)->start_idx)
		return (0);
	return (0);
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

int					etc_check(char *line, int idx, t_var **var)
{
	if (!line[idx + 1])
		return (1);
	if ((*var)->quote == 0 && is_in_char(line[idx + 1], "\'\""))
		return (1);
	if (line[idx + 1] == ' ')
		return (1);
	return (0);
}


void		init_var(t_var **var)
{
	(*var)->start_idx = -1;
	(*var)->end_idx = -1;
	(*var)->quote = 0;
	(*var)->quote_idx = -1;
	(*var)->prev = -1;
}

int			get_start_pos(char *line, int i, t_var **var)
{
	if (!line | !line[i])
		return (0);
	if (is_in_char(line[i], "\'\""))
	{
		if ((*var)->quote == line[i])
			return (0);
		(*var)->quote = line[i];
		(*var)->quote_idx = i;
		return (1);
	}
	if (is_in_char(line[i], ";<>|"))
	{
		if ((*var)->prev == line[i])
			return (0);
		(*var)->prev = line[i];
		return (1);
	}
	if (line[i] == ' ')
	{
		if (line[i - 1] == ' ')
			return (0);
	}
	if (line[i - 1] == ' ' || i == 0)
		return (1);
	else
		return (0);
}

int			get_end_pos(char *line, int i, t_var **var)
{
	if (!line | !line[i])
		return (0);
	if (is_in_char(line[i], "\'\""))
		return (quote_end_check(line, i, var));
	if (is_in_char(line[i], ";><|"))
		return (option_end_check(line, i, var));
	if (line[i] == ' ')
	{
		if (line[i + 1] == ' ')
			return (0);
		if (!line[i + 1])
			return (1);
	}
	return (etc_check(line, i, var));
}

int			get_doublestr_size(char **tokens)
{
	int		i;

	i = 0;
	while(tokens[i])
		i++;
	return (i);
}

void		free_arrs(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

char		**realloc_doublestr(char **tokens, char *token)
{
	char	**temp;
	int		size;

	size = 0;
	if (!tokens)
		tokens = malloc(sizeof(char *));
	if (tokens)
	{
		size = get_doublestr_size(tokens);
		temp = malloc(sizeof(char *) * (size + 2));
		temp[size + 1] = 0;
		ft_memcpy(temp, tokens, size);
		temp[size] = ft_strdup(token);
		// free_arrs(tokens);
	}
	return (temp);
}

char		**tokenization(char *line, t_var *var)
{
	char	*token;
	char	**tokens;
	int		i;

	init_var(&var);
	i = 0;
	token = 0;
	tokens = 0;
	while (line[i])
	{
		if (get_start_pos(line, i, &var))
		{
			var->start_idx = i;
		}
		if (get_end_pos(line, i, &var))
		{
			token = ft_substr(line, var->start_idx, (i - var->start_idx + 1));
			printf("%s\n", token);
			tokens = realloc_doublestr(tokens, token);
		}
		i++;
	}
	return (tokens);
}

int			parse_minishell(char *line, t_list **head)
{
	char	**tokens;
	int		i;
	t_var	var;

	tokens = 0;
	i = 0;
	// if (!(line = escaper(line)))
	// 	return (ERROR);
	tokens = tokenization(line, &var);
	return (0);
}

int				main(int argc, char *argv[], char *envp[])
{
	char		*line;
	char		*new_line;
	t_list		*head;

	head = NULL;
	init_list(&head, envp);
	while (1)
	{
		ft_putstr_fd("minishell$> ", 1);
		signal(SIGINT, signal_handler);
		while (get_next_line(0, &line) > 0)
			break;
		if (ft_strncmp(line, "exit", 4) == 0)
			exit(0);
		new_line = ft_strdup(line);
		free(line);
		if (parse_minishell(new_line, &head) == -1)
			printf("error\n");
	}
	return (0);
}
