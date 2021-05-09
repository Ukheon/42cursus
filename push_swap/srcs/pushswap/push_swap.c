/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:14:06 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/07 14:01:26 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void			div_half(t_info *info)
{
	int			i;
	int			check;
	int			save;
	int			save2;

	save = info->remain_arr_count[info->remain_idx];
	i = 0;
	if (info->remain_arr_count[info->remain_idx] % 2 == 1)
		info->remain_arr_count[info->remain_idx] = save / 2 + 1;
	else
		info->remain_arr_count[info->remain_idx] = save / 2;
	info->remain_arr_count[info->remain_idx + 1] = save / 2;
	init_stack(info);
	if (save % 2 == 1)
		info->center_idx = info->remain_arr_count[info->remain_idx] - 1;
	else
		info->center_idx = info->remain_arr_count[info->remain_idx];
	bubble_sort(info, &info->check_arr, save);
	info->center_value = info->check_arr[info->center_idx];
	// printf("%d %d\n", info->center_idx, info->center_value);
	if (info->flag == 0) // 시작이 A
	{
		while (info->center_idx > 0)
		{
			check = 0;
			while (check < info->a_size)
			{
				if (info->center_value > info->stack_a[i])
				{
					run_cmd(info, "pb\n");
					break ;
				}
				run_cmd(info, "ra\n");
				check++;
			}
			repeat_cmd(info, check, "rra\n");
			info->center_idx--;
		}
	}
	else // 시작이 B
	{
		while (info->center_idx > 0)
		{
			check = 0;
			while (check < info->b_size)
			{
				if (info->center_value > info->stack_b[i])
				{
					run_cmd(info, "pa\n");
					break ;
				}
				run_cmd(info, "rb\n");
				check++;
			}
			repeat_cmd(info, check, "rrb\n");
			info->center_idx--;
		}
	}
}


void			move_half_arr(t_info *info)
{
	g_check++;
	// printf("%d번째, FLAG = %d IDX = %d\n", g_check, info->flag, info->remain_idx);
	// for (int i = 0; i <= info->remain_idx; i++)
	// 	printf("remain[%d] = %d\n", i, info->remain_arr_count[i]);
	if (info->remain_arr_count[info->remain_idx] <= 3)
	{
		if (info->remain_arr_count[info->remain_idx] <= 3)
		{
			three_or_less(info);
		}
		if (info->remain_idx > 0)
		{
			info->remain_arr_count[info->remain_idx] = 0;
			info->remain_idx--;
		}
	}
	else
	{
		div_half(info);
		info->remain_idx++;
	}
	if (info->flag == 0)
		info->flag = 1;
	else
		info->flag = 0;
}

void			start_pushswap(t_info *info)
{
	int			res;
	int			count;

	count = 1;
	while (count)
	{
		if (check_finish(info, info->stack_a, info->a_size) && info->b_size == 0)
		{
			exit(0);
		}
		move_half_arr(info);
		// show_stack(info);
	}
}

int				main(int argc, char *argv[])
{
	t_info		info;
	int			i;
	int			j;

	g_check = 0;
	if (argc == 1)
		return (0);
	info.max_argument = argc - 1;
	set_info(&info, argc);
	if (get_argv_data(&info, argv))
		return (0);
	// printf("=====start=====\n");
	// for (int i = 0; i < info.a_size; i++)
	// 	printf("%d \n", info.stack_a[i]);
	// printf("\n");
	// bubble_sort(&info, &info.check_arr, info.max_argument / 5);
	start_pushswap(&info);
	return (0);
}
