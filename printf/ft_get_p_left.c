/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_p_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:53:50 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 17:59:21 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			p_left_check_five(t_flag *flag, long long p, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	p_i = flag->p_width - ft_strlen(str);
	flag->result += p_i > 0 ? p_i : 0;
	flag->result += 2;
	while (p_i-- > 0)
		write(1, "0", 1);
	write(1, "0x", 2);
	ft_putstr_fd((str), 1);
	free(str);
}

void			p_left_check_four(t_flag *flag, long long p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - ft_strlen(str) - 2;
	write(1, "0x", 2);
	ft_putstr_fd((str), 1);
	flag->result += i > 0 ? i + 2 : 0 + 2;
	while (i-- > 0)
		write(1, " ", 1);
	free(str);
}

void			p_left_check_thr(t_flag *flag, long long p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - flag->p_width - 2;
	flag->result += p_i > 0 ? p_i : 0;
	flag->result += 2;
	while (p_i-- > 0)
		write(1, "0", 1);
	write(1, "0x", 2);
	ft_putstr_fd((str), 1);
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	free(str);
}

void			p_left_check_two(t_flag *flag, long long p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - ft_strlen(str) - 2;
	write(1, "0x", 2);
	ft_putstr_fd((str), 1);
	flag->result += i > 0 ? i : 0;
	flag->result += 2;
	while (i-- > 0)
		write(1, " ", 1);
	free(str);
}

void			p_left_check(t_flag *flag, long long p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	if (flag->precision)
	{
		if (flag->width <= flag->p_width)
		{
			flag->result += 2;
			while (p_i-- > 0)
				write(1, "0", 1);
			write(1, "0x", 2);
			ft_putstr_fd((str), 1);
		}
		else if (flag->p_width < ft_strlen(str))
			p_left_check_two(flag, p, i);
		else
			p_left_check_thr(flag, p, i, p_i);
	}
	else if (flag->width)
		p_left_check_four(flag, p, i);
	else
		p_left_check_five(flag, p, p_i);
	free(str);
}
