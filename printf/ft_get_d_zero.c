/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_d_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:24:56 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/01 20:28:57 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			last_zero(t_flag *flag, long long int p, int i, int p_i)
{
	p_i = flag->p_width - ft_strlen(ft_itoa(p));
	i = flag->width - flag->p_width;
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	ft_putstr_fd((ft_itoa(p)), 1);
}

void			check_zero_two(t_flag *flag, long long int p, int i, int p_i)
{
	if (flag->width <= flag->p_width)
	{
		p_i = flag->p_width - ft_strlen(ft_itoa(p));
		flag->result += p_i > 0 ? p_i : 0;
		while (p_i-- > 0)
			write(1, "0", 1);
		ft_putstr_fd((ft_itoa(p)), 1);
	}
	else if (flag->p_width < ft_strlen(ft_itoa(p)))
	{
		i = flag->width - ft_strlen(ft_itoa(p));
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		ft_putstr_fd((ft_itoa(p)), 1);
	}
	else
		last_zero(flag, p, i, p_i);
}

void			check_zero(t_flag *flag, long long int p, int i, int p_i)
{
	if (flag->width && flag->p_width)
		check_zero_two(flag, p, i, p_i);
	else
	{
		i = flag->width - ft_strlen(ft_itoa(p));
		p_i = flag->p_width - ft_strlen(ft_itoa(p));
		i = i > p_i ? i : p_i;
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, "0", 1);
		ft_putstr_fd((ft_itoa(p)), 1);
	}
}
