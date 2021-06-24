/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:41 by ukwon             #+#    #+#             */
/*   Updated: 2021/06/17 20:42:32 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			set_exec_data(t_list **head)
{
	g_info.error = 0;
	g_info.enter_flag = 1;
	g_info.env = fill_env_data(head);
	ft_memset(g_info.buf, 0, 4096);
}

int				arr_row_check(char **split)
{
	int			i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void			signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		if (g_info.signal_flag == 0)
		{
			if (g_info.pid != 0)
				ft_putstr_fd("\n$> ", 1);
			init_info(0);
		}
		else
		{
			write(1, "\n", 1);
		}
	}
	if (signo == SIGQUIT)
	{
		if (g_info.signal_flag == 1)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_info.check2 = 1;
		}
	}
}

int				is_in_char(char ch, char *str)
{
	while (*str)
	{
		if (ch == *str)
			return (1);
		str++;
	}
	return (0);
}

int				is_space(char ch)
{
	if (ch >= 9 && ch <= 13)
		return (1);
	if (ch == ' ')
		return (1);
	return (0);
}
