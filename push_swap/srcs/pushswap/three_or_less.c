#include "../../include/push_swap.h"

void			case_a_three(t_info *info)
{
	if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] < info->check_arr[2])
	{
		if (info->remain_idx != 0)
			repeat_cmd(info, 3, "ra\n");
	}
	else if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] > \
	info->check_arr[2] && info->check_arr[2] > info->check_arr[0])
	{
		run_cmd(info, "ra\n");
		run_cmd(info, "sa\n");
		if (info->remain_idx != 0)
			repeat_cmd(info, 2, "ra\n");
	}
	else if (info->check_arr[0] > info->check_arr[1] && info->check_arr[1] < \
	info->check_arr[2] && info->check_arr[2] > info->check_arr[0])
	{
		run_cmd(info, "sa\n");
		if (info->remain_idx != 0)
			repeat_cmd(info, 3, "ra\n");
	}
	else if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] > \
	info->check_arr[2] && info->check_arr[2] < info->check_arr[0])
	{
		run_cmd(info, "ra\n");
		run_cmd(info, "sa\n");
		run_cmd(info, "rra\n");
		run_cmd(info, "sa\n");
		if (info->remain_idx != 0)
			repeat_cmd(info, 3, "ra\n");
	}
	else if (info->check_arr[0] > info->check_arr[1] && info->check_arr[1] < \
	info->check_arr[2] && info->check_arr[2] < info->check_arr[0])
	{
		run_cmd(info, "sa\n");
		run_cmd(info, "ra\n");
		run_cmd(info, "sa\n");
		if (info->remain_idx != 0)
			repeat_cmd(info, 2, "ra\n");
	}
	else
	{
		run_cmd(info, "sa\n");
		run_cmd(info, "ra\n");
		run_cmd(info, "sa\n");
		run_cmd(info, "rra\n");
		run_cmd(info, "sa\n");
		if (info->remain_idx != 0)
			repeat_cmd(info, 3, "ra\n");
	}
}

void			case_b_three(t_info *info)
{
	if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] < info->check_arr[2])
	{
		run_cmd(info, "sb\n");
		run_cmd(info, "rb\n");
		run_cmd(info, "sb\n");
		run_cmd(info, "rrb\n");
		run_cmd(info, "sb\n");
	}
	else if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] > \
	info->check_arr[2] && info->check_arr[2] > info->check_arr[0])
	{
		run_cmd(info, "sb\n");
		run_cmd(info, "rb\n");
		run_cmd(info, "sb\n");
		run_cmd(info, "rrb\n");
	}
	else if (info->check_arr[0] > info->check_arr[1] && info->check_arr[1] < \
	info->check_arr[2] && info->check_arr[2] > info->check_arr[0])
	{
		run_cmd(info, "rb\n");
		run_cmd(info, "sb\n");
		run_cmd(info, "rrb\n");
		run_cmd(info, "sb\n");
	}
	else if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] > \
	info->check_arr[2] && info->check_arr[2] < info->check_arr[0])
	{
		run_cmd(info, "rb\n");
		run_cmd(info, "sb\n");
		run_cmd(info, "rrb\n");
	}
	else if (info->check_arr[0] > info->check_arr[1] && info->check_arr[1] < \
	info->check_arr[2] && info->check_arr[2] < info->check_arr[0])
	{
		run_cmd(info, "rb\n");
		run_cmd(info, "sb\n");
		run_cmd(info, "rrb\n");
	}
}

void			find_case_a(t_info *info)
{
	if (info->remain_arr_count[info->remain_idx] == 3)
	{
		printf("check = %d\n", g_check);
		case_a_three(info);
		// if (info->remain_idx != 0)
		// 	repeat_cmd(info, 3, "ra\n");
	}
	else if (info->remain_arr_count[info->remain_idx] == 2)
	{
		if (info->check_arr[0] > info->check_arr[1])
			run_cmd(info, "sa\n");
		if (info->remain_idx != 0)
			repeat_cmd(info, 2, "ra\n");
		if (info->b_size == 0)
			repeat_cmd(info, 2, "ra\n");
	}
	else if (info->remain_arr_count[info->remain_idx] == 1)
		repeat_cmd(info, 1, "ra\n");
}

void			find_case_b(t_info *info)
{
	if (info->remain_arr_count[info->remain_idx] == 3)
	{
		case_b_three(info);
		repeat_cmd(info, 3, "pa\n");
		if (info->remain_idx != 0)
			repeat_cmd(info, 3, "ra\n");
	}
	else if (info->remain_arr_count[info->remain_idx] == 2)
	{
		if (info->check_arr[0] < info->check_arr[1])
			run_cmd(info, "sb\n");
		repeat_cmd(info, 2, "pa\n");
		if (info->remain_idx != 0)
			repeat_cmd(info, 2, "ra\n");
	}
	else if (info->remain_arr_count[info->remain_idx] == 1)
	{
		run_cmd(info, "pa\n");
		run_cmd(info, "ra\n");
	}
}

void			three_or_less(t_info *info)
{
	int			i;

	i = 0;
	get_stack_data(info);
	if (info->flag == 0)
	{
		find_case_a(info);
	}
	else
	{
		find_case_b(info);
	}
}
