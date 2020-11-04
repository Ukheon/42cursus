/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/04 14:00:05 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			x_pre_check_thr(t_flag *flag, long long p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - ft_strlen(str);
	flag->result += i > 0 ? i : 0;
	flag->result += ft_strlen(str);
	while (i-- > 0)
		write(1, " ", 1);
	if (flag->x_check == 0)
		ft_putstr_fd((str), 1);
	else
	{
		str = ft_itoa_base_upper(p, 16);
		ft_putstr_fd((str), 1);
	}
	free(str);
}

void			x_pre_check_two(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	p_i = flag->p_width - ft_strlen(str);
	i = flag->width - flag->p_width;
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	if (flag->x_check == 0)
		ft_putstr_fd((str), 1);
	else
	{
		str = ft_itoa_base_upper(p, 16);
		ft_putstr_fd((str), 1);
	}
	flag->result += ft_strlen(str);
	free(str);
}

void			x_pre_check(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	if (flag->width <= flag->p_width)
	{
		p_i = flag->p_width - ft_strlen(str);
		flag->result += p_i > 0 ? p_i : 0;
		flag->result += ft_strlen(str);
		while (p_i-- > 0)
			write(1, "0", 1);
		if (flag->x_check == 0)
			ft_putstr_fd((str), 1);
		else
		{
			str = ft_itoa_base_upper(p, 16);
			ft_putstr_fd((str), 1);
		}
	}
	else if (flag->p_width < ft_strlen(str))
		x_pre_check_thr(flag, p, i);
	else
		x_pre_check_two(flag, p, i, p_i);
}

void			x_error_check(t_flag *flag, long long int p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width;
	flag->result += i > 0 ? i : 0;
	flag->result -= 1;
	while (i-- > 0)
		write(1, " ", 1);
	flag->result += ft_strlen(str);
	if (flag->p_width < 0)
	{
		if (flag->x_check == 0)
			ft_putstr_fd((str), 1);
		else
		{
			str = str;
			ft_putstr_fd((str), 1);
		}
	}
	free(str);
}

void			get_x(t_flag *flag, va_list ap)
{
	unsigned int	p;
	int				i;
	int				p_i;

	i = 0;
	p_i = 0;
	p = va_arg(ap, unsigned int);
	if (p < 0)
		get_md(flag, (p * -1), i, p_i);
	else if (flag->precision && p == 0 && flag->p_width <= 0)
		x_error_check(flag, p, i);
	else if (flag->left)
		x_left_check(flag, p, i, p_i);
	else if (flag->zero)
		x_zero_check(flag, p, i, p_i);
	else if (flag->precision)
		x_pre_check(flag, p, i, p_i);
	else
		x_last_check(flag, p, i);
}
