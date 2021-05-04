#include "../../include/push_swap.h"

int			g_check;

void			init_stack(t_info *info)
{
	int			i;

	i = 0;
	while (i < info->max_argument)
	{
		info->check_arr[i] = 0;
		i++;
	}
}

void			b_to_a(t_info *info)
{
	int			i;
	int			check;

	i = 0;
	init_stack(info);
	info->center_idx = bubble_sort(info, &info->check_arr);
	info->center_value = info->check_arr[info->center_idx];
	info->remain_arr_count[info->remain_idx] = info->center_idx;
	info->last_remain_count = info->center_idx;
	while (info->center_idx > 0)
	{
		check = info->b_size;
		while (check)
		{
			if (info->center_value > info->stack_b[i])
			{
				run_cmd(info, "pa\n");
				break ;
			}
			run_cmd(info, "rb\n");
			check--;
		}
		info->center_idx--;
	}
}

void			a_to_b(t_info *info)
{
	int			i;
	int			check;

	i = 0;
	init_stack(info);
	info->center_idx = bubble_sort(info, &info->check_arr);
	info->center_value = info->check_arr[info->center_idx];
	info->remain_arr_count[info->remain_idx] = info->center_idx;
	info->last_remain_count = info->center_idx;
	while (info->center_idx > 0)
	{
		check = info->a_size;
		while (check)
		{
			if (info->center_value > info->stack_a[i])
			{
				run_cmd(info, "pb\n");
				break ;
			}
			run_cmd(info, "ra\n");
			check--;
		}
		info->center_idx--;
	}
}

void			div_half(t_info *info)
{
	if (info->flag == 0) // 시작이 A
	{
		a_to_b(info);
	}
	else // 시작이 B
	{
		b_to_a(info);
	}
}

void			get_stack_data(t_info *info)
{
	int			i;

	i = 0;
	init_stack(info);
	while (i < info->remain_arr_count[info->remain_idx])
	{
		if (info->flag == 0)
			info->check_arr[i] = info->stack_a[i];
		else
			info->check_arr[i] = info->stack_b[i];
		i++;
	}
}

void			case_a_three(t_info *info)
{
	if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] < info->check_arr[2])
	{
		return ;
	}
	else if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] > info->check_arr[2])
	{
		run_cmd(info, "sa\n");
		run_cmd(info, "ra\n");
	}
	else if (info->check_arr[0] > info->check_arr[1] && info->check_arr[1] < info->check_arr[2])
		run_cmd(info, "sa\n");
	else if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] > info->check_arr[2])
		run_cmd(info, "rra\n");
	else if (info->check_arr[0] > info->check_arr[1] && info->check_arr[1] < info->check_arr[2])
		run_cmd(info, "ra\n");
	else
	{
		run_cmd(info, "ra\n");
		run_cmd(info, "ra\n");
	}
}

void			count_ra(t_info *info, int count)
{
	int			i;

	i = 0;
	while (i < count)
	{
		run_cmd(info, "ra\n");
		i++;
	}
}

void			find_case_a(t_info *info)
{
	printf("herere?\n");
	if (info->remain_arr_count[info->remain_idx] == 3)
	{
		printf("g_check = %d\n",g_check);
		case_a_three(info);
		count_ra(info, 3);
	}
	if (info->remain_arr_count[info->remain_idx] == 2)
	{
		if (info->check_arr[0] > info->check_arr[1])
			run_cmd(info, "sa\n");
		count_ra(info, 2);
	}
	if (info->remain_arr_count[info->remain_idx] == 1)
		count_ra(info, 1);
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
}

void			five_or_less(info)
{
	
}

void			move_half_arr(t_info *info)
{
	g_check++;
	printf("여기는 [%d]번째 idx = %d,flag = %d\n",g_check, info->remain_idx, info->flag);
	if (info->remain_arr_count[info->remain_idx] <= 5)
	{
		if (info->remain_arr_count[info->remain_idx] <= 3)
		{
			three_or_less(info);
		}
		else
		{
			five_or_less(info);
		}
		if (info->remain_idx > 0)
			info->remain_idx--;
	}
	else
	{
		info->remain_idx++;
		div_half(info);
	}
	if (info->flag == 0)
		info->flag = 1;
	else
		info->flag = 0;
}

void			show_stack(t_info *info)
{
	int			i;
	int			j;
	int			temp;

	i = 0;
	temp = info->a_size;
	if (temp < info->b_size)
		temp = info->b_size;
	while (i < temp)
	{
		printf(" %d  |", i);
		if (info->a_size > i)
			printf("  %d|", info->stack_a[i]);
		else
			printf("    |");
		if (info->b_size > i)
			printf("   %d|", info->stack_b[i]);
		printf("\n");
		i++;
	}
	printf("\nidx |  A  |  B  |\n");
}

void			start_pushswap(t_info *info)
{
	char		buf[20];
	int			res;
	int			count;

	count = 8;
	ft_memset(buf, 0, 20);
	while (count--)
	{
		if (check_finish(info, info->stack_a) && info->b_size == 0)
			exit(0);
		move_half_arr(info);
		show_stack(info);
		ft_memset(buf, 0, 20);
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
	start_pushswap(&info);
	return (0);
}
