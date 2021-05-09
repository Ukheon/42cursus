/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:12:38 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/13 20:24:29 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (lst->key)
		(*del)(lst->key);
	lst->key = NULL;
	if (lst->value)
		(*del)(lst->value);
	lst->value = NULL;
	if (lst->redir)
		(*del)(lst->redir);
	lst->redir = NULL;
	if (lst->filename)
		(*del)(lst->filename);
	lst->filename = NULL;
	free(lst);
}
