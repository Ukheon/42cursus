/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:24 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/01 12:21:43 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token			*token_lstlast(t_token *lst)
{
	t_token		*new;

	if (!lst)
		return (0);
	new = lst;
	while (new->next)
		new = new->next;
	return (new);
}

t_token			*new_token(char *str)
{
	t_token		*new;

	if (!str)
		return (0);
	new = (t_token *)malloc(sizeof(t_token) * 1);
	if (!new)
		return (0);
	new->token = ft_strdup(str);
	new->next = 0;
	return (new);
}

void			token_add_back(t_token **tokens, t_token *new)
{
	t_token		*lstnew;

	if (!tokens || !new)
	{
		return ;
	}
	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	lstnew = token_lstlast(*tokens);
	lstnew->next = new;
	new->next = NULL;
}

void			check_list(t_list *head)
{
	while (head)
	{
		if (head->key && head->flag)
		{
			printf("%s=%s\n", head->key, head->value);
		}
		head = (head)->next;
	}
}
