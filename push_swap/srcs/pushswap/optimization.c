/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:24:06 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 15:35:06 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void			optimization(t_info *info)
{
	int			i;

	i = -1;
	info->r_count = 0;
	info->rr_count = 0;
	while (++i < info->a_size)
	{
		if (info->pivot_value == info->stack_a[i])
			break ;
		info->r_count++;
	}
	i = info->a_size;
	while (--i >= 0)
	{
		if (info->pivot_value == info->stack_a[i])
			break ;
		info->rr_count++;
	}
}

void			check_fast_road_b(t_info *info)
{
	int			i;

	i = -1;
	info->r_count = 0;
	info->rr_count = 0;
	while (++i < info->b_size)
	{
		if (info->pivot_value == info->stack_b[i])
			break ;
		info->r_count++;
	}
	i = info->b_size;
	while (--i >= 0)
	{
		if (info->pivot_value == info->stack_b[i])
			break ;
		info->rr_count++;
	}
}

void			check_fast_road_a(t_info *info)
{
	int			i;

	i = -1;
	info->r_count = 0;
	info->rr_count = 0;
	while (++i < info->a_size)
	{
		if (info->pivot_value >= info->stack_a[i])
			break ;
		info->r_count++;
	}
	i = info->a_size;
	while (--i >= 0)
	{
		if (info->pivot_value >= info->stack_a[i])
			break ;
		info->rr_count++;
	}
}
