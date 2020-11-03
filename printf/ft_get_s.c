/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:43:56 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 21:20:10 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			s_left_check(t_flag *flag, char *str, int i, int p_i)
{
	if (flag->p_width < 0)
	{
		i = (flag->width - ft_strlen(str)) > 0 ? flag->width - ft_strlen(str) : 0;
		ft_putstr_fd(str, 1);
		i = i > 0 ? i : 0;
		flag->result += (i + ft_strlen(str));
		while (i-- > 0)
			write(1, " ", 1);
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
			p_i = flag->p_width;
			i = (flag->width - ft_strlen(str)) > 0 ? flag->width - ft_strlen(str) : 0;
			str = ft_substr(str, 0, p_i);
			i = i > 0 ? i : 0;
			flag->result += (i + ft_strlen(str));
			ft_putstr_fd(str, 1);
			while (i-- > 0)
				write(1, " ", 1);
		}
		else
		{
			p_i = flag->p_width;
			i = ft_strlen(str) > p_i ? flag->width - p_i : flag->width - ft_strlen(str);
			i = i > 0 ? i : 0;
			str = ft_substr(str, 0, p_i);
			flag->result += (i + ft_strlen(str));
			ft_putstr_fd(str, 1);
			while (i-- > 0)
				write(1, " ", 1);
		}
	}
	else if (flag->width)
	{
		i = (flag->width - ft_strlen(str)) > 0 ? flag->width - ft_strlen(str) : 0;
		ft_putstr_fd(str, 1);
		i = i > 0 ? i : 0;
		flag->result += (i + ft_strlen(str));
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		ft_putstr_fd(str, 1);
		flag->result += (ft_strlen(str));
	}
}

void			get_s(t_flag *flag, va_list ap)
{
	char *str;
	int i;
	int p_i;

	i = 0;
	p_i = 0;
	str = va_arg(ap, char *);
	if (!str)
		null_s(flag);
	else if (flag->left)
		s_left_check(flag, str, i, p_i);
	else
	{
		if (flag->precision)
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
				p_i = flag->p_width;
				i = ft_strlen(str) > p_i ? \
				flag->width - p_i : flag->width - ft_strlen(str);
				i = i > 0 ? i : 0;
				if (!(str = ft_substr(str, 0, p_i)))
				{
					flag->result += p_i;
					write(1, "(null)", p_i);
					return ;
				}
				ft_substr(str, 0, p_i);
				flag->result += (i + ft_strlen(str));
				while (i-- > 0)
					write(1, " ", 1);
				ft_putstr_fd(str, 1);
			}
			else
			{
				p_i = flag->p_width;
				i = ft_strlen(str) > p_i ? flag->width - p_i : \
				flag->width - ft_strlen(str);
				i = i > 0 ? i : 0;
				flag->result += i;
				while (i-- > 0)
					write(1, " ", 1);
				if (!(str = ft_substr(str, 0, p_i)))
				{
					flag->result += ft_strlen(str);
					write(1, "(null)", p_i);
					return ;
				}
				flag->result += ft_strlen(str);
				ft_putstr_fd(str, 1);
			}
		}
		else
		{
			i = (flag->width - ft_strlen(str)) > 0 ? \
			flag->width - ft_strlen(str) : 0;
			flag->result += (i + ft_strlen(str));
			while (i-- > 0)
				write(1, " ", 1);
			ft_putstr_fd(str, 1);
		}
	}
}
