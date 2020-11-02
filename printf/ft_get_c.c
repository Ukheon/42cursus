/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:44:26 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/02 16:29:35 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			get_c(t_flag *flag, va_list ap)
{
	int		i;
	char	c;

	i = 0;
	c = va_arg(ap, int);
	if (flag->left)
	{
		i = flag->width - 1;
		flag->result += (i + 1);
		write(1, &c, 1);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		i = flag->width - 1;
		flag->result += (i + 2);
		while (i-- > 0)
			write(1, " ", 1);
		write(1, &c, 1);
	}
}

void			get_per(t_flag *flag)
{
	int		i;

	if (flag->left)
	{
		i = flag->width - 1;
		flag->result += i + 1;
		write(1, "%", 1);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else if (flag->zero)
	{
		i = flag->width - 1;
		flag->result += i + 1;
		while (i-- > 0)
			write(1, "0", 1);
		write(1, "%", 1);
	}
	else
	{
		i = flag->width - 1;
		flag->result += i + 1;
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "%", 1);
	}
}

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
				flag->result += i;
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
			i = i > 0 ? i : 0;
			flag->result += 6 + i;
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

void			get_s(t_flag *flag, va_list ap)
{
	char	*str;
	int		i;
	int		p_i;

	i = 0;
	str = va_arg(ap, char*);
	if (!str)
	{
		null_s(flag);
		return ;
	}
	if (flag->left)
	{
		if (flag->p_width < 0)
		{
			i = (flag->width - ft_strlen(str)) > 0 ? \
				flag->width-ft_strlen(str) : 0;
			ft_putstr_fd(str, 1);
			flag->result += (i + ft_strlen(str));
			while (i-- > 0)
				write(1, " ", 1);
		}
		else if (flag->precision)
		{
			if (flag->p_width == 0)
			{
				i = flag->width;
				flag->result += i;
				while (i-- > 0)
					write(1, " ", 1);
			}
			else if (flag->width <= flag->p_width)
			{
				p_i = flag->p_width;
				i = (flag->width - ft_strlen(str)) > 0 ? \
				flag->width - ft_strlen(str) : 0;
				str = ft_substr(str, 0, p_i);
				flag->result += (i + p_i);
				ft_putstr_fd(str, 1);
				while (i-- > 0)
					write(1, " ", 1);
			}
			else
			{
				p_i = flag->p_width;
				i = ft_strlen(str) > p_i ? flag->width - p_i : \
					flag->width - ft_strlen(str);
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
			i = (flag->width - ft_strlen(str)) > 0 ? \
				flag->width - ft_strlen(str) : 0;
			ft_putstr_fd(str, 1);
			flag->result += (i + ft_strlen(str));
			while (i-- > 0)
				write(1, " ", 1);
		}
	}
	else
	{
		if (flag->precision)
		{
			if (flag->p_width == 0)
			{
				flag->result += i;
				i = flag->width;
				while (i-- > 0)
					write(1, " ", 1);
			}
			else if (flag->width <= flag->p_width)
			{
				p_i = flag->p_width;
				i = ft_strlen(str) > p_i ? flag->width - p_i : \
					flag->width - ft_strlen(str);
				i = i > 0 ? i : 0;
				if (!(str = ft_substr(str, 0, p_i)))
				{
					flag->result += p_i;
					write(1, "(null)", p_i);
					return ;
				}
				ft_substr(str, 0, p_i);
				flag->result += (i + p_i);
				while (i-- > 0)
					write(1, " ", 1);
				ft_putstr_fd(str, 1);
			}
			else
			{
				p_i = flag->p_width;
				i = ft_strlen(str) > p_i ? flag->width - p_i : \
					flag->width - ft_strlen(str);
				flag->result += i;
				while (i-- > 0)
					write(1, " ", 1);
				if (!(str = ft_substr(str, 0, p_i)))
				{
					flag->result += p_i;
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
