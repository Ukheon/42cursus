/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:44:26 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 21:21:41 by ukwon            ###   ########.fr       */
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
		i = i > 0 ? i : 0;
		flag->result += (i + 1);
		write(1, &c, 1);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		i = flag->width - 1;
		i = i > 0 ? i : 0;
		flag->result += (i + 1);
		while (i-- > 0)
			write(1, " ", 1);
		write(1, &c, 1);
	}
}

void			get_per_sub(t_flag *flag, int i)
{
	i = flag->width - 1;
	i = i > 0 ? i : 0;
	flag->result += i + 1;
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "%", 1);
}

void			get_per(t_flag *flag)
{
	int		i;

	if (flag->left)
	{
		i = flag->width - 1;
		i = i > 0 ? i : 0;
		flag->result += i + 1;
		write(1, "%", 1);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else if (flag->zero)
	{
		i = flag->width - 1;
		i = i > 0 ? i : 0;
		flag->result += i + 1;
		while (i-- > 0)
			write(1, "0", 1);
		write(1, "%", 1);
	}
	else
		get_per_sub(flag, 0);
}
