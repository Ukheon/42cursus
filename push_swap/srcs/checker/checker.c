#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../include/checker.h"

void			start_pushswap(t_info *info)
{
	char		buf[100];
	int			res;
	char		*line;
	ft_memset(buf, 0, 100);
	while (get_next_line(0, &line) > 0)
	{
		// printf("why!!!!!!!!%s\n", line);
		run_cmd(info, line);
		ft_memset(buf, 0, 100);
	}
	// printf("why!!!!!!!!%s\n", line);
	run_cmd(info, line);
	if (check_finish(info, info->stack_a) && info->b_size == 0)
	{
		write(1, "OK\n", 3);
	}
	else
	{
		for (int i = 0; i < info->a_size; i++)
			printf("%d ", info->stack_a[i]);
		printf("\n");
		write(1, "KO\n", 3);
	}
}

int				check_error(t_info *info)
{
	int			i;
	int			j;

	i = 0;
	while (i < info->a_size)
	{
		j = i + 1;
		while (j < info->a_size)
		{
			if (info->stack_a[i] == info->stack_a[j])
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
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
	if (check_error(&info))
		return (0);
	info.center_idx = bubble_sort(&info, info.check_arr);
	info.center_value = info.check_arr[info.center_idx];
	start_pushswap(&info);
	return (0);
}
