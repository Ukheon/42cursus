/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_p_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:15:43 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 17:59:38 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			p_zero_check_four(t_flag *flag, long long int p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - ft_strlen(str) - 2;
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	ft_putstr_fd((str), 1);
	free(str);
}

void			p_zero_check_thr(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	p_i = flag->p_width - ft_strlen(str) - 2;
	i = flag->width - flag->p_width - 2;
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	write(1, "0x", 2);
	ft_putstr_fd((str), 1);
	free(str);
}

void			p_zero_check_two(t_flag *flag, long long int p, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	p_i = flag->p_width - ft_strlen(str) - 2;
	flag->result += p_i > 0 ? p_i : 0;
	while (p_i-- > 0)
		write(1, "0", 1);
	write(1, "0x", 2);
	ft_putstr_fd((str), 1);
	free(str);
}

void			p_zero_check(t_flag *flag, long long int p, int i, int p_i)
{
	char			*str;

	str = ft_itoa_base_lower(p, 16);
	if (flag->width && flag->p_width)
	{
		if (flag->width <= flag->p_width)
			p_zero_check_two(flag, p, p_i);
		else if (flag->p_width < ft_strlen(str))
			p_zero_check_four(flag, p, i);
		else
			p_zero_check_thr(flag, p, i, p_i);
	}
	else
	{
		i = flag->width - ft_strlen(str);
		p_i = flag->p_width - ft_strlen(str);
		i = i > p_i ? i : p_i;
		flag->result += i > 0 ? i + 2 : 0 + 2;
		while (i-- > 0)
			write(1, "0", 1);
		write(1, "0x", 2);
		ft_putstr_fd((str), 1);
	}
	free(str);
}
