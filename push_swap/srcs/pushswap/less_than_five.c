/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:29:57 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 15:34:45 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void			find_case_b(t_info *info)
{
	int			idx;
	int			i;

	i = 0;
	idx = 2;
	while (idx--)
	{
		info->pivot_value = info->check_arr[i++];
		optimization(info);
		loop_a_to_b(info, 1);
	}
	find_case_a(info);
	run_cmd(info, "pa\n");
	run_cmd(info, "pa\n");
}

void			find_case_a(t_info *info)
{
	if (info->a_size == 3)
	{
		case_a_three(info);
	}
	else if (info->a_size == 2)
	{
		if (info->stack_a[0] > info->stack_a[1])
			run_cmd(info, "sa\n");
	}
	else
		return ;
}

void			case_a_three(t_info *info)
{
	if (info->stack_a[0] < info->stack_a[1] && \
	info->stack_a[1] < info->stack_a[2])
		return ;
	else if (info->stack_a[0] < info->stack_a[1] && info->stack_a[1] \
	> info->stack_a[2] && info->stack_a[2] > info->stack_a[0])
	{
		run_cmd(info, "ra\n");
		run_cmd(info, "sa\n");
		run_cmd(info, "rra\n");
	}
	else if (info->stack_a[0] > info->stack_a[1] && info->stack_a[1] \
	< info->stack_a[2] && info->stack_a[2] > info->stack_a[0])
		run_cmd(info, "sa\n");
	else if (info->stack_a[0] < info->stack_a[1] && info->stack_a[1] \
	> info->stack_a[2] && info->stack_a[2] < info->stack_a[0])
		run_cmd(info, "rra\n");
	else if (info->stack_a[0] > info->stack_a[1] && info->stack_a[1] \
	< info->stack_a[2] && info->stack_a[2] < info->stack_a[0])
		run_cmd(info, "ra\n");
	else
	{
		run_cmd(info, "sa\n");
		run_cmd(info, "rra\n");
	}
}
