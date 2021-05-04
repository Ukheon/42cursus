/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:33 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/01 12:29:11 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			exec_echo(t_token **tokens, int flag)
{
	g_info.idx = 0;
	g_info.echo_flag = 0;
	while ((*tokens)->argv[++g_info.idx])
	{
		if (g_info.idx == 1 && ft_strcmp((*tokens)->argv[g_info.idx], "-n") \
		== 0)
		{
			flag = 1;
			g_info.echo_flag = 1;
			continue ;
		}
		if (flag == 1 && ft_strcmp((*tokens)->argv[g_info.idx], "-n") == 0)
			continue ;
		if (g_info.idx == arr_row_check((*tokens)->argv) - 1)
			ft_putstr_fd((*tokens)->argv[g_info.idx], 1);
		else
		{
			ft_putstr_fd((*tokens)->argv[g_info.idx], 1);
			write(1, " ", 1);
		}
		flag = 0;
	}
	if (g_info.echo_flag != 1)
		printf("\n");
}
