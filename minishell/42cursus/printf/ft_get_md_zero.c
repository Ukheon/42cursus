/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_md_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:23:49 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 18:40:06 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			md_zero_four(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	i = flag->width - ft_strlen(str);
	p_i = flag->p_width - ft_strlen(str);
	i = i > p_i ? i : p_i;
	i = i - 1;
	write(1, "-", 1);
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, "0", 1);
	ft_putstr_fd((str), 1);
	free(str);
}

void			md_zero_thr(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	p_i = flag->p_width - ft_strlen(str);
	i = flag->width - flag->p_width - 1;
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "-", 1);
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	ft_putstr_fd((str), 1);
	free(str);
}

void			md_zero_two(t_flag *flag, long long int p, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	write(1, "-", 1);
	p_i = flag->p_width - ft_strlen(str);
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	ft_putstr_fd((str), 1);
	free(str);
}

void			md_zero_check(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	if (flag->p_width)
	{
		if (flag->width <= flag->p_width)
			md_zero_two(flag, p, p_i);
		else if (flag->p_width < ft_strlen(str))
		{
			i = flag->width - ft_strlen(str) - 1;
			flag->result += i > 0 ? i : 0;
			while (i-- > 0)
				write(1, " ", 1);
			write(1, "-", 1);
			ft_putstr_fd((str), 1);
		}
		else
			md_zero_thr(flag, p, i, p_i);
	}
	else
		md_zero_four(flag, p, i, p_i);
	free(str);
}
