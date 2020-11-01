/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_md.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/01 21:04:07 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			get_md(t_flag *flag, long long int p, int i, int p_i)
{
	if (flag->left)
	{
		if (flag->width && flag->p_width)
		{
			if (flag->width <= flag->p_width)
			{
				write(1, "-", 1);
				p_i = flag->p_width - ft_strlen(ft_itoa(p));
				flag->result += p_i > 0 ? p_i : 0;
				while (p_i-- > 0)
					write(1, "0", 1);
				ft_putstr_fd((ft_itoa(p)), 1);
			}
			else if (flag->p_width < ft_strlen(ft_itoa(p)))
			{
				i = flag->width - ft_strlen(ft_itoa(p)) - 1;
				write(1, "-", 1);
				ft_putstr_fd((ft_itoa(p)), 1);
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
			}
			else
			{
				write(1, "-", 1);
				p_i = flag->p_width - ft_strlen(ft_itoa(p));
				i = flag->width - flag->p_width - 1;
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
			write(1, "-", 1);
			i = flag->width - ft_strlen(ft_itoa(p)) - 1;
			ft_putstr_fd((ft_itoa(p)), 1);
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
		}
		else
		{
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			flag->result += p_i > 0 ? p_i : 0;
			write(1, "-", 1);
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
				write(1, "-", 1);
				p_i = flag->p_width - ft_strlen(ft_itoa(p));
				flag->result += p_i > 0 ? p_i : 0;
				while (p_i-- > 0)
					write(1, "0", 1);
				ft_putstr_fd((ft_itoa(p)), 1);
			}
			else if (flag->p_width < ft_strlen(ft_itoa(p)))
			{
				i = flag->width - ft_strlen(ft_itoa(p)) - 1;
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
				write(1, "-", 1);
				ft_putstr_fd((ft_itoa(p)), 1);
			}
			else
			{
				p_i = flag->p_width - ft_strlen(ft_itoa(p));
				i = flag->width - flag->p_width - 1;
				flag->result += i > 0 ? i : 0;
				while (i-- > 0)
					write(1, " ", 1);
				write(1, "-", 1);
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
			i = i - 1;
			write(1, "-", 1);
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
			write(1, "-", 1);
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			flag->result += p_i > 0 ? p_i : 0;
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
		else if (flag->p_width < ft_strlen(ft_itoa(p)))
		{
			i = flag->width - ft_strlen(ft_itoa(p)) - 1;
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
			write(1, "-", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
		else
		{
			p_i = flag->p_width - ft_strlen(ft_itoa(p));
			i = flag->width - flag->p_width - 1;
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
			write(1, "-", 1);
			flag->result += p_i > 0 ? p_i : 0;
			while (p_i-- > 0)
				write(1, "0", 1);
			ft_putstr_fd((ft_itoa(p)), 1);
		}
	}
	else
	{
		i = flag->width - ft_strlen(ft_itoa(p)) - 1;
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "-", 1);
		ft_putstr_fd((ft_itoa(p)), 1);
	}
}
