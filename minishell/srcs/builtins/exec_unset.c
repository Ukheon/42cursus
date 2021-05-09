/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:53 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 14:26:41 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			exec_unset(t_token **tokens, t_list **head)
{
	g_info.idx = 0;
	while ((*tokens)->argv[++g_info.idx])
	{
		if (check_valid_var((*tokens)->argv[g_info.idx]))
		{
			printf("$> unset: `%s': not a valid identifier\n", \
			(*tokens)->argv[g_info.idx]);
			continue ;
		}
		unset_list(head, ((*tokens)->argv[g_info.idx]));
	}
}

void			pipe_exec_unset(t_token **tokens, t_list **head, int num)
{
	g_info.idx = 0;
	while ((*tokens)->argv[++g_info.idx])
	{
		if (check_valid_var((*tokens)->argv[g_info.idx]))
		{
			printf("$> : unset: `%s': not a valid identifier\n", \
			(*tokens)->argv[g_info.idx]);
			if (num == 1)
				return ;
			exit(3);
		}
		unset_list(head, ((*tokens)->argv[g_info.idx]));
	}
}
