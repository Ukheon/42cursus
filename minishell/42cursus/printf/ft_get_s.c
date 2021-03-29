/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:43:56 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/04 17:26:55 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			s_pre_check_thr(t_flag *flag, char *str, int i, int p_i)
{
	p_i = flag->p_width;
	i = ft_strlen(str) > p_i ? flag->width - p_i : flag->width - ft_strlen(str);
	i = i > 0 ? i : 0;
	flag->result += i;
	while (i-- > 0)
		write(1, " ", 1);
	if (!str)
	{
		flag->result += ft_strlen(str);
		write(1, "(null)", p_i);
		return ;
	}
	flag->result += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void			s_pre_check_two(t_flag *flag, char *str, int i, int p_i)
{
	p_i = flag->p_width;
	i = ft_strlen(str) > p_i ? flag->width - p_i : flag->width - ft_strlen(str);
	i = i > 0 ? i : 0;
	if (!str)
	{
		flag->result += p_i;
		write(1, "(null)", p_i);
		return ;
	}
	flag->result += (i + ft_strlen(str));
	while (i-- > 0)
		write(1, " ", 1);
	ft_putstr_fd(str, 1);
}

void			s_pre_check(t_flag *flag, char *str, int i, int p_i)
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
			s_pre_check_two(flag, str, i, p_i);
		else
			s_pre_check_thr(flag, str, i, p_i);
	}
	else
	{
		i = (flag->width - ft_strlen(str)) > 0 ?\
			flag->width - ft_strlen(str) : 0;
		flag->result += (i + ft_strlen(str));
		while (i-- > 0)
			write(1, " ", 1);
		ft_putstr_fd(str, 1);
	}
}

void			get_s(t_flag *flag, va_list ap)
{
	char		*str;
	int			i;
	int			p_i;
	char		*va;

	i = 0;
	p_i = 0;
	va = va_arg(ap, char *);
	if (!va)
	{
		null_s(flag, 0, 0);
		return ;
	}
	str = ft_strdup(va);
	if (flag->p_width > 0)
	{
		free(str);
		str = ft_substr(str, 0, flag->p_width);
	}
	if (flag->left)
		s_left_check(flag, str, i, p_i);
	else
		s_pre_check(flag, str, i, p_i);
	free(str);
}
