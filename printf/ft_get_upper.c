/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/01 18:13:47 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			get_upper(t_flag *flag, va_list ap)
{
	long long int	p;
	int				i;
	int				p_i;

	p = va_arg(ap, long long int);
	flag->result += ft_strlen(ft_itoa_base_X(p, 16));
	if (p < 0)
	{
		p *= -1;
		get_md(flag, p);
		return ;
	}
	if (flag->precision && p == 0 && flag->p_width <= 0)
	{
		i = flag->width;
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		if (flag->p_width < 0)
			ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
	}
	else if (flag->left)
	{
		if (flag->width && flag->p_width)
		{
			if (flag->width <= flag->p_width)
			{
				p_i = flag->p_width - ft_strlen(ft_itoa_base_X(p, 16));
				flag->result += p_i > 0 ? p_i : 0;
				while (p_i-- > 0)
					write(1, "0", 1);
				ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
			}
			else if (flag->p_width < ft_strlen(ft_itoa_base_X(p, 16)))
			{
				i = flag->width - ft_strlen(ft_itoa_base_X(p, 16));
				ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
			}
			else
			{
				p_i = flag->p_width - ft_strlen(ft_itoa_base_X(p, 16));
				i = flag->width - flag->p_width;
				flag->result += p_i > 0 ? p_i : 0;
				while (p_i-- > 0)
					write(1, "0", 1);
				ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
			}
		}
		else if (flag->width)
		{
			i = flag->width - ft_strlen(ft_itoa_base_X(p, 16));
			ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
		}
		else
		{
			p_i = flag->p_width - ft_strlen(ft_itoa_base_X(p, 16));
			flag->result += p_i > 0 ? p_i : 0;
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
		}
	}
	else if (flag->zero)
	{
		if (flag->width && flag->p_width)
		{
			if (flag->width <= flag->p_width)
			{
				p_i = flag->p_width - ft_strlen(ft_itoa_base_X(p, 16));
				flag->result += p_i > 0 ? p_i : 0;
				while (p_i-- > 0)
					write(1, "0", 1);
				ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
			}
			else if (flag->p_width < ft_strlen(ft_itoa_base_X(p, 16)))
			{
				i = flag->width - ft_strlen(ft_itoa_base_X(p, 16));
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
				ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
			}
			else
			{
				p_i = flag->p_width - ft_strlen(ft_itoa_base_X(p, 16));
				i = flag->width - flag->p_width;
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
				flag->result += p_i > 0 ? p_i : 0;
				while (p_i-- > 0)
					write(1, "0", 1);
				ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
			}
		}
		else
		{
			i = flag->width - ft_strlen(ft_itoa_base_X(p, 16));
			p_i = flag->p_width - ft_strlen(ft_itoa_base_X(p, 16));
			i = i > p_i ? i : p_i;
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
		}
	}
	else if (flag->precision)
	{
		if (flag->width <= flag->p_width)
		{
			p_i = flag->p_width - ft_strlen(ft_itoa_base_X(p, 16));
			flag->result += p_i > 0 ? p_i : 0;
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
		}
		else if (flag->p_width < ft_strlen(ft_itoa_base_X(p, 16)))
		{
			i = flag->width - ft_strlen(ft_itoa_base_X(p, 16));
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
			ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
		}
		else
		{
			p_i = flag->p_width - ft_strlen(ft_itoa_base_X(p, 16));
			i = flag->width - flag->p_width;
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
			flag->result += p_i > 0 ? p_i : 0;
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
		}
	}
	else
	{
		i = flag->width - ft_strlen(ft_itoa_base_X(p, 16));
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		ft_putstr_fd((ft_itoa_base_X(p, 16)), 1);
	}
}
