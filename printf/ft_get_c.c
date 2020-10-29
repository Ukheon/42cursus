/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:44:26 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/29 21:36:49 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_c(t_flag *flag, va_list ap)
{
	int		i;
	char	c;

	c = va_arg(ap, int);
	if (flag->left)
	{
		i = flag->width - 1;
		flag->result = i + 1;
		write(1, &c, 1);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		i = flag->width - 1;
		flag->result = i + 1;
		while (i-- > 0)
			write(1, " ", 1);
		write(1, &c, 1);
	}
}

void			get_s(t_flag *flag, va_list ap)
{
	char	*str;
	int		i;
	int		p_i;

	str = va_arg(ap, char*);
	if (flag->left)
	{
		if (flag->p_width)
		{
			if (flag->width <= flag->p_width)
			{
				p_i = flag->p_width;
				i = flag->width - ft_strlen(str);
				str = ft_substr(str, 0, p_i);
				ft_putstr_fd(str, 1);
				while (i-- > 0)
					write(1, " ", 1);
			}
			else
			{
				p_i = flag->p_width;
				i = ft_strlen(str) > p_i ? flag->width - p_i : \
					flag->width - ft_strlen(str);
				str = ft_substr(str, 0, p_i);
				ft_putstr_fd(str, 1);
				while (i-- > 0)
					write(1, " ", 1);
			}
		}
		else if (flag->width)
		{
			i = flag->width - ft_strlen(str);
			ft_putstr_fd(str, 1);
			while (i-- > 0)
				write(1, " ", 1);
		}
	}
	else
	{
		if (flag->precision)
		{
			if (flag->width <= flag->p_width)
			{
				p_i = flag->p_width;
				i = flag->width - ft_strlen(str);
				str = ft_substr(str, 0, p_i);
				while (i-- > 0)
					write(1, " ", 1);
				ft_putstr_fd(str, 1);
			}
			else
			{

			}
		}
		else
		{
			i = flag->width - ft_strlen(str);
			while (i-- > 0)
				write(1, " ", 1);
			ft_putstr_fd(str, 1);
		}
	}
}
