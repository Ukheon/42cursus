/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:14:36 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 14:22:51 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int				argv_check(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[0] == '0' && str[1] == '0')
			return (1);
		if (str[0] == '-')
			continue ;
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (1);
	}
	return (0);
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
