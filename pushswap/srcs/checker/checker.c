#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../include/checker.h"

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
			printf("  %d  |", info->stack_a[i]);
		else
			printf("     |");
		if (info->b_size > i)
			printf("  %d  |", info->stack_b[i]);
		printf("\n");
		i++;
	}
	printf("\nidx |  A  |  B  |\n");
}

void			start_pushswap(t_info *info)
{
	char		buf[20];
	int			res;

	ft_memset(buf, 0, 20);
	while (read(0, buf, 20))
	{
		run_cmd(info, buf);
		show_stack(info);
		if (check_finish(info, info->stack_a) && info->b_size == 0)
		{
			write(1, "OK\n", 3);
			exit(0);
		}
		ft_memset(buf, 0, 20);
	}
}

int			main(int argc, char *argv[])
{
	t_info		info;
	int			i;
	int			j;

	if (argc == 1)
		return (0);
	info.max_argument = argc - 1;
	set_info(&info, argc);
	if (get_argv_data(&info, argv))
		return (0);
	info.center_idx = bubble_sort(&info, info.check_arr);
	info.center_value = info.check_arr[info.center_idx];
	start_pushswap(&info);
	return (0);
}