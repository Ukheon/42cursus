/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_md.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/04 13:13:32 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			md_pre_last(t_flag *flag, long long int p, int i, int p_i)
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

void			md_pre_check(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	if (flag->width <= flag->p_width)
	{
		write(1, "-", 1);
		p_i = flag->p_width - ft_strlen(str);
		flag->result += p_i > 0 ? p_i : 0;
		while (p_i-- > 0)
			write(1, "0", 1);
		ft_putstr_fd((str), 1);
	}
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
		md_pre_last(flag, p, i, p_i);
	free(str);
}

void			md_error_check(t_flag *flag, long long int p, int i)
{
	char	*str;

	str = ft_itoa(p);
	i = flag->width - ft_strlen(str) - 1;
	flag->result += i > 0 ? i : 0;
	if (flag->left)
	{
		write(1, "-", 1);
		ft_putstr_fd((str), 1);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "-", 1);
		ft_putstr_fd((str), 1);
	}
	free(str);
}

void			get_md(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa(p);
	if (flag->precision && flag->p_width <= 0)
		md_error_check(flag, p, i);
	else if (flag->left)
		md_left_check(flag, p, i, p_i);
	else if (flag->zero)
		md_zero_check(flag, p, i, p_i);
	else if (flag->precision)
		md_pre_check(flag, p, i, p_i);
	else
	{
		i = flag->width - ft_strlen(str) - 1;
		flag->result += i > 0 ? i : 0;
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "-", 1);
		ft_putstr_fd((str), 1);
	}
	free(str);
}
