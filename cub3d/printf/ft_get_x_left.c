/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_x_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:36:40 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/04 16:41:41 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			x_left_check_five(t_flag *flag, long long int p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - ft_strlen(str);
	flag->result += ft_strlen(str);
	if (flag->x_check == 0)
		ft_putstr_fd((str), 1);
	else
	{
		free(str);
		str = ft_itoa_base_upper(p, 16);
		ft_putstr_fd(str, 1);
	}
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	free(str);
}

void			x_left_check_four(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	p_i = flag->p_width - ft_strlen(str);
	i = flag->width - flag->p_width;
	flag->result += p_i > 0 ? p_i : 0;
	flag->result += ft_strlen(str);
	while (p_i-- > 0)
		write(1, "0", 1);
	if (flag->x_check == 0)
		ft_putstr_fd((str), 1);
	else
	{
		free(str);
		str = ft_itoa_base_upper(p, 16);
		ft_putstr_fd(str, 1);
	}
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	free(str);
}

void			x_left_check_thr(t_flag *flag, long long int p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - ft_strlen(str);
	flag->result += ft_strlen(str);
	if (flag->x_check == 0)
		ft_putstr_fd((str), 1);
	else
	{
		free(str);
		str = ft_itoa_base_upper(p, 16);
		ft_putstr_fd(str, 1);
	}
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	free(str);
}

void			x_left_check_two(t_flag *flag, long long int p, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	p_i = flag->p_width - ft_strlen(str);
	flag->result += p_i > 0 ? p_i : 0;
	flag->result += ft_strlen(str);
	while (p_i-- > 0)
		write(1, "0", 1);
	if (flag->x_check == 0)
		ft_putstr_fd((str), 1);
	else
	{
		free(str);
		str = ft_itoa_base_upper(p, 16);
		ft_putstr_fd(str, 1);
	}
	free(str);
}

void			x_left_check(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	if (flag->width && flag->p_width)
	{
		if (flag->width <= flag->p_width)
			x_left_check_two(flag, p, p_i);
		else if (flag->p_width < ft_strlen(str))
			x_left_check_thr(flag, p, i);
		else
			x_left_check_four(flag, p, i, p_i);
	}
	else if (flag->width)
		x_left_check_five(flag, p, i);
	else
		x_left_check_last(flag, p, p_i);
	free(str);
}
