/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_md.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/28 20:05:33 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_md(t_flag *flag, int p)
{
	int i;
	int	p_i;

	if (flag->left)
	{
		write(1, "-", 1);
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
			i = flag->width - (ft_strlen(ft_itoa(p)) + p_i) - 1;
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
			write(1, "-", 1);
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
		else
		{
			p_i = flag->p_width > ft_strlen(ft_itoa(p)) ? \
			(flag->p_width) - ft_strlen(ft_itoa(p)) : 0;
			i = flag->width - (ft_strlen(ft_itoa(p)) + p_i) - 1;
			while (i-- > 0)
				write(1, " ", 1);
			write(1, "-", 1);
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
	}
	else if (flag->precision)
	{
		if (flag->width <= flag->p_width)
		{
			write(1, "-", 1);
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
		else
		{
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			i = flag->p_width - p_i - 1;
			while (i-- > 0)
				write(1, " ", 1);
			write(1, "-", 1);
			while (p_i-- > 0)
				write(1, "0", 1);
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
