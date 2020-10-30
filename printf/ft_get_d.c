/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/30 16:39:02 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			get_d(t_flag *flag, va_list ap)
{
	int p;
	int i;
	int	p_i;

	p = va_arg(ap, int);
	flag->result += ft_strlen(ft_itoa(p));
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
			ft_putstr_fd((ft_itoa(p)), 1);
	}
	else if (flag->left)
	{
		if (flag->width && flag->p_width)
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
				ft_putstr_fd((ft_itoa(p)), 1);
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
			}
			else
			{
				p_i = flag->p_width - ft_strlen(ft_itoa(p));
				i = flag->width - flag->p_width;
				flag->result += p_i > 0 ? p_i : 0;
				while (p_i-- > 0)
					write(1, "0", 1);
				ft_putstr_fd((ft_itoa(p)), 1);
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
			}
		}
		else if (flag->width)
		{
			i = flag->width - ft_strlen(ft_itoa(p));
			ft_putstr_fd((ft_itoa(p)), 1);
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
		}
		else
		{
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			flag->result += p_i > 0 ? p_i : 0;
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
	}
	else if (flag->zero)
	{
		if (flag->width && flag->p_width)
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
		}
		else
		{
			i = flag->width - ft_strlen(ft_itoa(p));
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			i = i > p_i ? i : p_i;
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
	}
	else if (flag->precision)
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
	}
	else
	{
		i = flag->width - ft_strlen(ft_itoa(p));
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		ft_putstr_fd((ft_itoa(p)), 1);
	}
}
