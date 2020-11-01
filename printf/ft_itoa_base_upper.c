/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:37:30 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/01 19:29:46 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_itoa_base_X(long long int value, int base)
{
	int size;
	long long int save_value;
	char *res;

	save_value = value;
	size = 0;
	if (value == 0)
		return (ft_strdup("0"));
	if (save_value < 0 && base == 10)
	{
		save_value *= -1;
		size += 1;
	}
	while (save_value)
	{
		save_value /= base;
		size++;
	}
	save_value = value;
	res = (char *)malloc(sizeof(char) * size + 1);
	if (save_value < 0 && base == 10)
	{
		res[0] = '-';
		save_value *= -1;
	}
	res[size] = '\0';
	size--;
	while (save_value)
	{
		if (save_value % base > 9)
			res[size] = save_value % base + 'A' - 10;
		else
			res[size] = (save_value % base) + '0';
		save_value /= base;
		size--;
	}
	return (res);
}
