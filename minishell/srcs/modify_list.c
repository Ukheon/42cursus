/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:26 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 14:26:27 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			export_add_list(t_token **tokens, t_list **head, int num)
{
	int			i;

	i = 1;
	while ((*tokens)->argv[i])
	{
		export_list(head, (*tokens)->argv[i], num);
		i++;
	}
	return ;
}

void			add_list(t_list **head, char *str, int num)
{
	int			i;
	char		**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		export_list(head, split[i], num);
		i++;
	}
	free_split(split);
	return ;
}

void			unset_list(t_list **head, char *str)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*prev;

	temp = *head;
	while (temp)
	{
		if ((ft_strncmp(temp->key, str, ft_strlen(temp->key)) == 0))
		{
			temp2 = temp->next;
			prev->next = temp2;
			ft_lstdelone(temp, free);
			temp = temp2;
			continue ;
		}
		prev = temp;
		temp = temp->next;
	}
}
