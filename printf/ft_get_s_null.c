/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:45:38 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 18:45:53 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			null_s(t_flag *flag)
{
	int		p_i;
	int		i;

	if (flag->left)
	{
		if (flag->p_width < 0)
		{
			flag->result += 6;
			write(1, "(null)", 6);
		}
		else if (flag->precision)
		{
			if (flag->p_width == 0)
			{
				i = flag->width;
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
			}
			else if (flag->width <= flag->p_width)
			{
				p_i = flag->p_width > 6 ? 6 : flag->p_width;
				write(1, "(null)", p_i);
				i = flag->width - p_i;
				i = i > 0 ? i : 0;
				flag->result += p_i + i;
				while (i-- > 0)
					write(1, " ", 1);
			}
			else
			{
				p_i = flag->p_width > 6 ? 6 : flag->p_width;
				write(1, "(null)", p_i);
				i = flag->width - p_i;
				i = i > 0 ? i : 0;
				flag->result += p_i + i;
				while (i-- > 0)
					write(1, " ", 1);
			}
		}
		else
		{
			i = flag->width - 6;
			write(1, "(null)", 6);
			flag->result += i > 0 ? i : 0;
			flag->result += 6;
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
		else
		{
			i = flag->width - 6;
			i = i > 0 ? i : 0;
			flag->result += 6 + i;
			while (i-- > 0)
				write(1, " ", 1);
			write(1, "(null)", 6);
		}
	}
}
