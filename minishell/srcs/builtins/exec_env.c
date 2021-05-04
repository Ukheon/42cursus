/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:35 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/24 19:47:32 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			exec_env(t_token **tokens, t_list **head)
{
	g_info.idx = arr_row_check((*tokens)->argv);
	if (g_info.idx == 1)
		check_list(*head);
	else
		g_info.error = 1;
}
