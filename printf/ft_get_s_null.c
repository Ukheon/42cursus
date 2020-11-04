/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:45:38 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/04 13:53:03 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			null_s_pre_thr(t_flag *flag, int i)
{
	i = flag->width - 6;
	i = i > 0 ? i : 0;
	flag->result += 6 + i;
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "(null)", 6);
}

void			null_s_pre_two(t_flag *flag, int i, int p_i)
{
	if (flag->width <= flag->p_width)
	{
		p_i = flag->p_width > 6 ? 6 : flag->p_width;
		i = flag->width - p_i;
		i = i > 0 ? i : 0;
		flag->result += p_i + i;
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "(null)", p_i);
	}
	else
	{
		p_i = flag->p_width > 6 ? 6 : flag->p_width;
		i = flag->width - p_i;
		i = i > 0 ? i : 0;
		flag->result += p_i + i;
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "(null)", p_i);
	}
}

void			null_s_pre(t_flag *flag, int i, int p_i)
{
	if (flag->p_width == 0)
	{
		i = flag->width;
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		return ;
	}
	else if (flag->width <= flag->p_width)
	{
		p_i = flag->p_width > 6 ? 6 : flag->p_width;
		write(1, "(null)", p_i);
		i = (flag->width - p_i) > 0 ? (flag->width - p_i) : 0;
		flag->result += p_i + i;
		while (i-- > 0)
			write(1, " ", 1);
		return ;
	}
	p_i = flag->p_width > 6 ? 6 : flag->p_width;
	write(1, "(null)", p_i);
	i = flag->width - p_i;
	i = i > 0 ? i : 0;
	flag->result += p_i + i;
	while (i-- > 0)
		write(1, " ", 1);
}

void			null_s(t_flag *flag, int i, int p_i)
{
	if (flag->left)
	{
		if (flag->p_width < 0)
		{
			flag->result += 6;
			write(1, "(null)", 6);
		}
		else if (flag->precision)
			null_s_pre(flag, i, p_i);
		else
		{
			i = flag->width - 6;
			write(1, "(null)", 6);
			flag->result += i > 0 ? i : 0;
			flag->result += 6;
			while (i-- > 0)
				write(1, " ", 1);
		}
		return ;
	}
	if (flag->precision)
		null_s_pre_two(flag, i, p_i);
	else
		null_s_pre_thr(flag, i);
}
