/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:22 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 18:05:56 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				loop_read_check(t_list **history, t_list **temp, \
t_list **head, char *new_line)
{
	new_line = NULL;
	if (g_info.history_flag)
	{
		*temp = (*history)->next;
		free((*history)->history);
		free(*history);
		(*history) = *temp;
	}
	if (g_info.c == 4)
		exit(0);
	if (!*g_info.buf)
	{
		ft_putstr_fd("$> ", 1);
		return (0);
	}
	ft_lstadd_front(history, new_history(g_info.buf));
	new_line = ft_strdup(g_info.buf);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_info.default_term);
	ft_memset(g_info.buf, 0, 4096);
	g_info.status = parse_minishell(new_line, head);
	free(new_line);
	ft_putstr_fd("$> ", 1);
	return (0);
}

int				check_char(long long int num, t_list **history)
{
	get_cursor_position(&g_info.col, &g_info.row, 1, 0);
	g_info.check2 = 0;
	if (num == 4 || num == LEFT_ARROW || num == RIGHT_ARROW || num == 9)
	{
		if (num == 4)
			if (!g_info.buf[0])
				exit(0);
		g_info.c = 0;
		return (1);
	}
	if (num == BACKSPACE)
	{
		delete_end();
		return (1);
	}
	else if (g_info.c == UP_ARROW || g_info.c == DOWN_ARROW)
	{
		if (g_info.c == UP_ARROW)
			g_info.his_idx++;
		else
			g_info.his_idx--;
		call_history(history);
		return (1);
	}
	return (0);
}

int				push_num(char *str)
{
	int			len;
	int			res;

	len = (int)ft_strlen(str) - 1;
	res = 0;
	while (len >= 0)
	{
		res = res * 256 + str[len];
		len--;
	}
	return (res);
}

void			minishell_start(t_list **head, t_list **history, t_list **temp)
{
	char		*new_line;

	new_line = NULL;
	while (read(0, &g_info.c, sizeof(g_info.c)) > 0)
	{
		*temp = *history;
		if (check_char(g_info.c, history))
			continue ;
		else
		{
			g_info.write_flag = 1;
			write(0, &g_info.c, 1);
		}
		if (g_info.c == 10)
			break ;
		g_info.buf[g_info.idx] = g_info.c;
		g_info.idx++;
		g_info.c = 0;
	}
	loop_read_check(history, temp, head, new_line);
}

int				main(int argc, char *argv[], char *envp[])
{
	t_list		*head;
	t_list		*history;
	t_list		*temp;

	wellcome_massage();
	argc = 0;
	argv = (void *)0;
	init_term();
	head = NULL;
	history = NULL;
	init_list(&head, envp);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	ft_putstr_fd("$> ", 1);
	while (1)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &g_info.term);
		init_info(0);
		minishell_start(&head, &history, &temp);
	}
	return (0);
}
