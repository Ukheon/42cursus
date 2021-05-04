/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:38 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 15:30:48 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int				numeric_error_check(t_token **tokens, int num)
{
	char	*temp;

	if (arr_row_check((*tokens)->argv) == 1)
		return (0);
	temp = (*tokens)->argv[1];
	while (*temp)
	{
		if (!(*temp >= '0' && *temp <= '9'))
		{
			if (num == 0)
				printf("exit\n$>: %s: %s: numeric argument required\n", \
				(*tokens)->cmd, (*tokens)->argv[1]);
			else
				printf("$>: %s: %s: numeric argument required\n", \
				(*tokens)->cmd, (*tokens)->argv[1]);
			g_info.error = 255;
			return (1);
		}
		temp++;
	}
	return (0);
}

int				many_argv_check(t_token **tokens, int num)
{
	g_info.idx = arr_row_check((*tokens)->argv);
	if (g_info.idx > 2)
	{
		if (num == 0)
			printf("exit\n$>: %s: too many arguments\n", (*tokens)->cmd);
		else
			printf("$>: %s: too many arguments\n", (*tokens)->cmd);
		g_info.error = 1;
		return (1);
	}
	return (0);
}

int				exec_exit(t_token **tokens, int num)
{
	g_info.idx = arr_row_check((*tokens)->argv);
	if (g_info.idx == 1)
	{
		if (num == 1)
			printf("exit\n");
		return (0);
	}
	if (numeric_error_check(tokens, 0))
		return (2);
	if (many_argv_check(tokens, 0))
		return (1);
	if (num == 1)
		printf("exit\n");
	g_info.error = ft_atoi((*tokens)->argv[1]) % 256;
	return (0);
}
