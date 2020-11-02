/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/02 20:51:52 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			check_pre_last(t_flag *flag, long long int p, int i, int p_i)
{
	p_i = flag->p_width - ft_strlen(ft_itoa(p));
	i = flag->width - flag->p_width;
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	ft_putstr_fd((ft_itoa(p)), 1);
}

void			check_precision(t_flag *flag, long long int p, int i, int p_i)
{
	if (flag->width <= flag->p_width)
	{
		p_i = flag->p_width - ft_strlen(ft_itoa(p));
		flag->result += p_i > 0 ? p_i : 0;
		while (p_i-- > 0)
			write(1, "0", 1);
		ft_putstr_fd((ft_itoa(p)), 1);
	}
	else if (flag->p_width < ft_strlen(ft_itoa(p)))
	{
		i = flag->width - ft_strlen(ft_itoa(p));
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		ft_putstr_fd((ft_itoa(p)), 1);
	}
	else
		check_pre_last(flag, p, i, p_i);
}

void			last_check(t_flag *flag, long long int p, int i)
{
	i = flag->width - ft_strlen(ft_itoa(p));
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	ft_putstr_fd((ft_itoa(p)), 1);
}

void			error_check(t_flag *flag, long long int p, int i)
{
	i = flag->width;
	flag->result += i > 0 ? i : 0;
	flag->result -= 1;
	while (i-- > 0)
		write(1, " ", 1);
	if (flag->p_width < 0)
		ft_putstr_fd((ft_itoa(p)), 1);
}

void			get_d(t_flag *flag, va_list ap)
{
	long long int	p;
	int				i;
	int				p_i;

	i = 0;
	p_i = 0;
	p = (long long int)va_arg(ap, int);
	flag->result += ft_strlen(ft_itoa(p));
	if (p < 0)
	{
		p *= -1;
		get_md(flag, p, i, p_i);
		return ;
	}
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
}
