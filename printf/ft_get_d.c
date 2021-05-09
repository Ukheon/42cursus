/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 18:00:02 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			check_pre_last(t_flag *flag, long long int p, int i, int p_i)
{
	char			*str;

	str = ft_itoa(p);
	p_i = flag->p_width - ft_strlen(str);
	i = flag->width - flag->p_width;
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	ft_putstr_fd((str), 1);
	free(str);
}

void			check_precision(t_flag *flag, long long int p, int i, int p_i)
{
	char			*str;

	str = ft_itoa(p);
	if (flag->width <= flag->p_width)
	{
		p_i = flag->p_width - ft_strlen(str);
		flag->result += p_i > 0 ? p_i : 0;
		while (p_i-- > 0)
			write(1, "0", 1);
		ft_putstr_fd((str), 1);
	}
	else if (flag->p_width < ft_strlen(str))
	{
		i = flag->width - ft_strlen(str);
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		ft_putstr_fd((str), 1);
	}
	else
		check_pre_last(flag, p, i, p_i);
	free(str);
}

void			last_check(t_flag *flag, long long int p, int i)
{
	char			*str;

	str = ft_itoa(p);
	i = flag->width - ft_strlen(str);
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	ft_putstr_fd((str), 1);
	free(str);
}

void			error_check(t_flag *flag, long long int p, int i)
{
	char			*str;

	str = ft_itoa(p);
	i = flag->width;
	flag->result += i > 0 ? i : 0;
	flag->result -= 1;
	while (i-- > 0)
		write(1, " ", 1);
	if (flag->p_width < 0)
		ft_putstr_fd((str), 1);
	free(str);
}

void			get_d(t_flag *flag, va_list ap)
{
	long long int	p;
	int				p_i;
	char			*str;

	p = (long long int)va_arg(ap, int);
	str = ft_itoa(p);
	p_i = 0;
	flag->result += ft_strlen(str);
	if (p < 0)
		get_md(flag, (p * -1), 0, p_i);
	else if (flag->precision && p == 0 && flag->p_width <= 0)
		error_check(flag, p, 0);
	else if (flag->left)
		check_left(flag, p, 0, p_i);
	else if (flag->zero)
		check_zero(flag, p, 0, p_i);
	else if (flag->precision)
		check_precision(flag, p, 0, p_i);
	else
		last_check(flag, p, 0);
	free(str);
}
