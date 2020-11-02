/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_x_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:47:00 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/02 16:55:50 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			x_zero_check_four(t_flag *flag, long long int p, int i, int p_i)
{
	i = flag->width - ft_strlen(ft_itoa_base_lower(p, 16));
	p_i = flag->p_width - ft_strlen(ft_itoa_base_lower(p, 16));
	i = i > p_i ? i : p_i;
	flag->result += i > 0 ? i : 0;
	flag->result += ft_strlen(ft_itoa_base_lower(p, 16));
	while (i-- > 0)
		write(1, "0", 1);
	if (flag->x_check == 0)
		ft_putstr_fd((ft_itoa_base_lower(p, 16)), 1);
	else
		ft_putstr_fd((ft_itoa_base_upper(p, 16)), 1);
}

void			x_zero_check_thr(t_flag *flag, long long int p, int i, int p_i)
{
	p_i = flag->p_width - ft_strlen(ft_itoa_base_lower(p, 16));
	i = flag->width - flag->p_width;
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	flag->result += p_i > 0 ? p_i : 0;
	flag->result += ft_strlen(ft_itoa_base_lower(p, 16));
	while (p_i-- > 0)
		write(1, "0", 1);
	if (flag->x_check == 0)
		ft_putstr_fd((ft_itoa_base_lower(p, 16)), 1);
	else
		ft_putstr_fd((ft_itoa_base_upper(p, 16)), 1);
}

void			x_zero_check_two(t_flag *flag, long long int p, int p_i)
{
	p_i = flag->p_width - ft_strlen(ft_itoa_base_lower(p, 16));
	flag->result += ft_strlen(ft_itoa_base_lower(p, 16));
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	if (flag->x_check == 0)
		ft_putstr_fd((ft_itoa_base_lower(p, 16)), 1);
	else
		ft_putstr_fd((ft_itoa_base_upper(p, 16)), 1);
}

void			x_zero_check(t_flag *flag, long long int p, int i, int p_i)
{
	if (flag->width && flag->p_width)
	{
		if (flag->width <= flag->p_width)
			x_zero_check_two(flag, p, p_i);
		else if (flag->p_width < ft_strlen(ft_itoa_base_lower(p, 16)))
		{
			flag->result += ft_strlen(ft_itoa_base_lower(p, 16));
			i = flag->width - ft_strlen(ft_itoa_base_lower(p, 16));
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
			if (flag->x_check == 0)
				ft_putstr_fd((ft_itoa_base_lower(p, 16)), 1);
			else
				ft_putstr_fd((ft_itoa_base_upper(p, 16)), 1);
		}
		else
			x_zero_check_thr(flag, p, i, p_i);
	}
	else
		x_zero_check_four(flag, p, i, p_i);
}
