/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:14:37 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 16:13:39 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void			move_arr(t_info *info, t_arr **head)
{
	int			count;

	count = 0;
	info->start_idx = 0;
	info->move_loop = 1;
	while (info->move_loop != (int)(info->max_loop + 1))
	{
		info->pivot = (info->max_argument / info->max_loop) \
		* info->move_loop - 1;
		lstadd_front(head, lstnew(info, (int)(info->pivot - \
		info->start_idx + 1)));
		count = (int)info->pivot + 1;
		info->pivot_value = info->check_arr[(int)(info->pivot)];
		while (count - info->start_idx)
		{
			check_fast_road_a(info);
			loop_a_to_b(info, 0);
			count--;
		}
		info->start_idx = (int)info->pivot + 1;
		info->move_loop++;
	}
}

void			sort_arr(t_info *info, t_arr **head)
{
	int			idx;
	t_arr		*temp;

	while (*head)
	{
		idx = (*head)->count;
		while (idx--)
		{
			info->pivot_value = (*head)->arr[idx];
			check_fast_road_b(info);
			loop_b_to_a(info);
		}
		temp = (*head)->next;
		free((*head)->arr);
		free((*head));
		(*head) = temp;
	}
	free((*head));
}

void			start_pushswap(t_info *info)
{
	t_arr		*head;

	head = NULL;
	info->move_loop = 0;
	bubble(info, &info->check_arr);
	if (info->max_argument <= 5)
	{
		if (info->max_argument <= 3)
			find_case_a(info);
		else
			find_case_b(info);
		return ;
	}
	while (1)
	{
		if (check_finish(info, info->stack_a) && info->b_size == 0)
		{
			return ;
		}
		move_arr(info, &head);
		sort_arr(info, &head);
	}
}

int				main(int argc, char *argv[])
{
	t_info		info;

	if (argc == 1)
		return (0);
	info.max_argument = argc - 1;
	set_info(&info, argc);
	if (get_argv_data(&info, argv))
		return (0);
	if (check_error(&info))
		return (0);
	start_pushswap(&info);
	return (0);
}
