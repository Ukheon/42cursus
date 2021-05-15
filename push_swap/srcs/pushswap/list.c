/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:14:33 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 14:15:22 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_arr			*lstlast(t_arr *lst)
{
	t_arr *new;

	if (!lst)
		return (0);
	new = lst;
	while (new->next)
		new = new->next;
	return (new);
}

void			lstadd_front(t_arr **lst, t_arr *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_arr			*lstnew(t_info *info, int count)
{
	t_arr		*new;
	int			i;
	int			j;

	if (!(new = (t_arr *)malloc(sizeof(t_arr) * 1)))
		return (0);
	new->count = count;
	new->arr = (int *)malloc(sizeof(int) * (int)(info->pivot + 1));
	i = 0;
	j = (int)info->start_idx;
	while (i < count)
	{
		new->arr[i] = info->check_arr[j];
		j++;
		i++;
	}
	new->next = 0;
	return (new);
}
