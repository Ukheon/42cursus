/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_x_remain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:12:04 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/04 16:15:27 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			x_zero_check_last(t_flag *flag, long long int p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	flag->result += ft_strlen(str);
	i = flag->width - ft_strlen(str);
	flag->result += i > 0 ? i : 0;
	while (i-- > 0)
		write(1, " ", 1);
	if (flag->x_check == 0)
		ft_putstr_fd((str), 1);
	else
	{
		free(str);
		str = ft_itoa_base_upper(p, 16);
		ft_putstr_fd((str), 1);
	}
	free(str);
}

void			x_left_check_last(t_flag *flag, long long int p, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	p_i = flag->p_width - ft_strlen(str);
	flag->result += ft_strlen(str);
	flag->result += p_i > 0 ? p_i : 0;
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
