/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:31:55 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 15:34:25 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int				bubble_sort(t_info *info, int *arr)
{
	int			i;
	int			j;
	int			temp;

	i = 0;
	while (i < info->a_size)
	{
		j = 0;
		while (j < info->a_size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = info->a_size / 2;
	return (i);
}

void			set_info(t_info *info, int argc)
{
	info->a_size = argc - 1;
	info->b_size = 0;
	info->stack_a = (int *)malloc(sizeof(int) * info->a_size);
	info->stack_b = (int *)malloc(sizeof(int) * info->a_size);
	info->check_arr = (int *)malloc(sizeof(int) * info->a_size);
	info->flag = 0;
	info->not_found = 0;
	info->max_argument = info->a_size;
}

int				get_argv_data(t_info *info, char *argv[])
{
	int			i;
	int			j;

	i = -1;
	j = 1;
	while (++i < info->max_argument)
	{
		if (argv_check(argv[j]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		info->stack_a[i] = ft_atoi(argv[j]);
		if ((info->stack_a[i] == 0 || info->stack_a[i] == -1) \
		&& ft_strlen(argv[j]) >= 3)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		info->check_arr[i] = ft_atoi(argv[j++]);
	}
	return (0);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			return (int)(str1[i] - str2[i]);
		}
		i++;
	}
	return (int)(str1[i] - str2[i]);
}

int				check_finish(t_info *info, int *arr)
{
	int			i;
	int			len;

	len = info->a_size;
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
