/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/28 20:05:37 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_d(t_flag *flag, va_list ap)
{
	int p;
	int i;
	int	p_i;

	p = va_arg(ap, int);
	if (p < 0)
	{
		p *= -1;
		get_md(flag, p);
		return ;
	}
	if (flag->left)
	{
		if (flag->width <= flag->p_width)
		{
			i = flag->p_width - ft_strlen(ft_itoa(p));
			while (i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
		else
		{
			p_i = flag->p_width > ft_strlen(ft_itoa(p)) ? \
			(flag->p_width) - ft_strlen(ft_itoa(p)) : 0;
			i = flag->width - (ft_strlen(ft_itoa(p)) + p_i);
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
			while (i-- > 0)
				write(1, " ", 1);
		}
	}
	else if (flag->zero)
	{
		if (flag->width <= flag->p_width)
		{
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
		else
		{
			p_i = flag->p_width > ft_strlen(ft_itoa(p)) ? \
			(flag->p_width) - ft_strlen(ft_itoa(p)) : 0;
			i = flag->width - (ft_strlen(ft_itoa(p)) + p_i);
			while (i-- > 0)
				write(1, " ", 1);
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
	}
	else if (flag->precision)
	{
		if (flag->width <= flag->p_width)
		{
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
		else
		{
			i = flag->p_width - ft_strlen(ft_itoa(p));
			while (i-- > 0)
				write(1, " ", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
	}
	else
	{
		i = flag->p_width - ft_strlen(ft_itoa(p));
		while (i-- > 0)
			write(1, " ", 1);
		ft_putstr_fd((ft_itoa(p)), 1);
	}
}
