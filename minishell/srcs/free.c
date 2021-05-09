/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:15 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/01 12:23:39 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			token_lstdelone(t_token *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (lst->cmd)
		(*del)(lst->cmd);
	lst->cmd = NULL;
	if (lst->argv)
		free_split(lst->argv);
	lst->argv = NULL;
	if (lst->token)
		(*del)(lst->token);
	lst->token = NULL;
	if (lst->redir_list)
	{
		(*del)(lst->redir_list);
	}
	lst->redir_list = NULL;
	free(lst);
}

void			free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
	}
	free(split);
}
