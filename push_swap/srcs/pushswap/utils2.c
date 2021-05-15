/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:27:33 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 14:31:35 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void			bubble(t_info *info, int **arr)
{
	int			i;
	int			j;
	int			temp;

	i = 0;
	while (i < info->max_argument)
	{
		j = 0;
		while (j < info->max_argument - 1)
		{
			if ((*arr)[j] > (*arr)[j + 1])
			{
				temp = (*arr)[j];
				(*arr)[j] = (*arr)[j + 1];
				(*arr)[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void			loop_b_to_a(t_info *info)
{
	while (1)
	{
		if (info->pivot_value == info->stack_b[0])
		{
			run_cmd(info, "pa\n");
			break ;
		}
		if (info->r_count < info->rr_count)
			run_cmd(info, "rb\n");
		else
			run_cmd(info, "rrb\n");
	}
}

void			loop_a_to_b(t_info *info, int flag)
{
	while (1)
	{
		if (flag == 0)
		{
			if (info->pivot_value >= info->stack_a[0])
			{
				run_cmd(info, "pb\n");
				break ;
			}
		}
		else if (info->pivot_value == info->stack_a[0])
		{
			run_cmd(info, "pb\n");
			break ;
		}
		if (info->r_count <= info->rr_count)
			run_cmd(info, "ra\n");
		else
			run_cmd(info, "rra\n");
	}
}
