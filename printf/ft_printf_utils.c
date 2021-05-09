/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:58:03 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/04 17:54:41 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char			*ft_itoa_base_upper(long long int value, int base)
{
	int				size;
	long long int	save_value;
	char			*res;

	save_value = value;
	size = 0;
	if (value == 0)
		return (ft_strdup("0"));
	while (save_value)
	{
		save_value /= base;
		size++;
	}
	save_value = value;
	res = (char *)malloc(sizeof(char) * size + 1);
	res[size--] = '\0';
	while (save_value)
	{
		if (save_value % base > 9)
			res[size--] = save_value % base + 'A' - 10;
		else
			res[size--] = (save_value % base) + '0';
		save_value /= base;
	}
	return (res);
}

char			*ft_itoa_base_lower(long long int value, int base)
{
	int				size;
	long long int	save_value;
	char			*res;

	save_value = value;
	size = 0;
	if (value == 0)
		return (ft_strdup("0"));
	while (save_value)
	{
		save_value /= base;
		size++;
	}
	save_value = value;
	res = (char *)malloc(sizeof(char) * size + 1);
	res[size--] = '\0';
	while (save_value)
	{
		if (save_value % base > 9)
			res[size--] = save_value % base + 'a' - 10;
		else
			res[size--] = (save_value % base) + '0';
		save_value /= base;
	}
	return (res);
}

void			reset_flag(t_flag *flag)
{
	flag->width = 0;
	flag->zero = 0;
	flag->left = 0;
	flag->p_width = 0;
	flag->precision = 0;
	flag->check = 0;
	flag->x_check = 0;
	flag->len = 0;
}

void			x_last_check(t_flag *flag, long long int p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - ft_strlen(str);
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	flag->result += ft_strlen(str);
	if (flag->x_check == 0)
		ft_putstr_fd(str, 1);
	else
	{
		free(str);
		str = ft_itoa_base_upper(p, 16);
		ft_putstr_fd(str, 1);
	}
	free(str);
}

void			get_u(t_flag *flag, va_list ap)
{
	unsigned int	p;
	int				i;
	int				p_i;
	char			*str;

	p = va_arg(ap, unsigned int);
	str = ft_itoa(p);
	i = 0;
	p_i = 0;
	flag->result += ft_strlen(str);
	if (flag->precision && p == 0 && flag->p_width <= 0)
		error_check(flag, p, i);
	else if (flag->left)
		check_left(flag, p, i, p_i);
	else if (flag->zero)
		check_zero(flag, p, i, p_i);
	else if (flag->precision)
		check_precision(flag, p, i, p_i);
	else
		last_check(flag, p, i);
	free(str);
}
