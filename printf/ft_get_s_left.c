/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:14:30 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 19:18:25 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			s_left_check_two(t_flag *flag, char *str, int i)
{
	i = (flag->width - ft_strlen(str)) > 0 ? \
	flag->width - ft_strlen(str) : 0;
	ft_putstr_fd(str, 1);
	i = i > 0 ? i : 0;
	flag->result += (i + ft_strlen(str));
	while (i-- > 0)
		write(1, " ", 1);
}

void			s_left_check(t_flag *flag, char *str, int i, int p_i)
{
	if (flag->p_width < 0)
		s_left_check_two(flag, str, i);
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
			i = (flag->width - ft_strlen(str)) > 0 ? \
				flag->width - ft_strlen(str) : 0;
			str = ft_substr(str, 0, p_i);
			i = i > 0 ? i : 0;
			flag->result += (i + ft_strlen(str));
			ft_putstr_fd(str, 1);
			free(str);
			while (i-- > 0)
				write(1, " ", 1);
		}
		else
		{
			p_i = flag->p_width;
			i = ft_strlen(str) > p_i ? flag->width - p_i \
			: flag->width - ft_strlen(str);
			i = i > 0 ? i : 0;
			str = ft_substr(str, 0, p_i);
			flag->result += (i + ft_strlen(str));
			ft_putstr_fd(str, 1);
			free(str);
			while (i-- > 0)
				write(1, " ", 1);
		}
	}
	else if (flag->width)
	{
		i = (flag->width - ft_strlen(str)) > 0 ? \
		flag->width - ft_strlen(str) : 0;
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
