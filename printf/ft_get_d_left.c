/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_d_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:17:12 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/04 19:32:22 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			last_left(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	p_i = flag->p_width - ft_strlen(str);
	i = flag->width - flag->p_width;
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	ft_putstr_fd((str), 1);
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	free(str);
}

void			check_left_two(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	if (flag->width <= flag->p_width)
	{
		p_i = flag->p_width - ft_strlen(str);
		flag->result += p_i > 0 ? p_i : 0;
		while (p_i-- > 0)
			write(1, "0", 1);
		ft_putstr_fd((str), 1);
	}
	else if (flag->p_width < ft_strlen(str))
	{
		i = flag->width - ft_strlen(str);
		ft_putstr_fd((str), 1);
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
		last_left(flag, p, i, p_i);
	free(str);
}

void			check_left(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	if (flag->width && flag->p_width)
		check_left_two(flag, p, i, p_i);
	else if (flag->width)
	{
		i = flag->width - ft_strlen(str);
		ft_putstr_fd((str), 1);
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		p_i = flag->p_width - ft_strlen(str);
		flag->result += p_i > 0 ? p_i : 0;
		while (p_i-- > 0)
			write(1, "0", 1);
		ft_putstr_fd((str), 1);
	}
	free(str);
}
