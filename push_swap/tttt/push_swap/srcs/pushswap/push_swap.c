#include "../../include/push_swap.h"

void			move_arr(t_info *info)
{
	int			check;
	int			count;
	int			check2;

	check2 = 0;
	count = info->max_argument / 5;
	check = 0;
	info->pivot = (info->max_argument / 5) * info->loop_count;
	if (info->loop_count == 5)
		info->pivot -= 1;
	info->center_value = info->check_arr[info->pivot];
	if (info->loop_count == 5)
		info->center_value += 1;
	while (count != check2)
	{
		if (info->center_value > info->stack_a[0])
		{
			check2++;
			run_cmd(info, "pb\n");
		}
		else
		{
			run_cmd(info, "ra\n");
			check++;
		}
	}
	if (info->loop_count != 1)
		repeat_cmd(info, check, "rra\n");
	info->loop_count++;
}

void			mov_front_arr(t_info *info)
{
	int			i;
	int			temp[3];
	int			loop;

	loop = 3;
	while (loop)
	{
		i = 0;
		while (i < info->count - 4)
		{
			info->remain_arr[i] = info->remain_arr[i + 1];
			i++;
		}
		loop--;
	}
}


void			sort_a(t_info *info)
{
	int			*temp;

	temp = (int *)malloc(sizeof(int) * 3);
	numcpy(info, &temp, 3, info->stack_a);
	case_a_three(info, temp);
	free(temp);
}

void			sort_and_pile(t_info *info)
{
	int			data;
	int			remainder;
	int			stop;

	stop = 0;
	info->count = info->max_argument / 5;
	info->loop = info->count / 3;
	remainder = info->count % 3;
	numcpy(info, &info->temp_b, info->count, info->stack_b);
	bubble_sort(info, &info->temp_b, info->count);
	data = info->temp_b[3];
	if (info->loop == 1)
	{
		data = info->temp_b[2];
		data += 1;
	}
	while (info->loop)
	{
		if (info->loop_count == 6 && info->loop == 1 && remainder == 0)
		{
			data = info->temp_b[2];
			data += 1;
		}
		stop = 0;
		while (info->b_size)
		{
			if (data > info->stack_b[0])
			{
				run_cmd(info, "pa\n");
				stop++;
			}
			if (stop == 3)
				break ;
			run_cmd(info, "rb\n");
		}
		mov_front_arr(info);
		sort_a(info);
		data = info->temp_b[3];
		info->loop--;
	}
	if (remainder != 0)
	{
		if (remainder == 1)
		{
			run_cmd(info, "pa\n");
			run_cmd(info, "ra\n");
		}
		else
		{
			// printf("%d vs %d\n", info->stack_b[0], info->stack_b[1]);
			if (info->stack_b[0] < info->stack_b[1])
				run_cmd(info, "sb\n");
			repeat_cmd(info, 2, "pa\n");
			repeat_cmd(info, 2, "ra\n");
		}
	}
}

void			set_sort(t_info *info)
{

}

void			start_pushswap(t_info *info)
{
	int			res;
	int			count;

	set_sort(info);
	while (1)
	{
		if (check_finish(info, info->stack_a, info->a_size) && info->b_size == 0)
		{
			exit(0);
		}
		move_arr(info);
		sort_and_pile(info);
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
	bubble_sort(&info, &info.check_arr, info.max_argument);
	start_pushswap(&info);
	return (0);
}
