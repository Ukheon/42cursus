/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:32:07 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 16:09:07 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../include/checker.h"

void			start_pushswap(t_info *info)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		run_cmd(info, line);
		free(line);
	}
	run_cmd(info, line);
	free(line);
	if (check_finish(info, info->stack_a) && info->b_size == 0)
	{
		write(1, "OK\n", 3);
	}
	else
	{
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
	info.center_idx = bubble_sort(&info, info.check_arr);
	info.center_value = info.check_arr[info.center_idx];
	start_pushswap(&info);
	return (0);
}
