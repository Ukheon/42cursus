/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 17:59:50 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			p_pre_last_check(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	p_i = flag->p_width - ft_strlen(str);
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

void			p_last_check(t_flag *flag, long long int p, int i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	i = flag->width - ft_strlen(str) - 2;
	flag->result += i > 0 ? i + 2 : 0 + 2;
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	ft_putstr_fd((str), 1);
	free(str);
}

void			p_pre_check(t_flag *flag, long long int p, int i, int p_i)
{
	char	*str;

	str = ft_itoa_base_lower(p, 16);
	if (flag->p_width)
	{
		p_i = flag->p_width - ft_strlen(str);
		flag->result += p_i > 0 ? p_i : 0;
		while (p_i-- > 0)
			write(1, "0", 1);
		write(1, "0x", 2);
		ft_putstr_fd((str), 1);
	}
	else if (flag->p_width < ft_strlen(str))
	{
		i = flag->width - ft_strlen(str) - 2;
		flag->result += i > 0 ? i + 2 : 0 + 2;
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "0x", 2);
		ft_putstr_fd((str), 1);
	}
	else
		p_pre_last_check(flag, p, i, p_i);
	free(str);
}

void			p_error_check(t_flag *flag, int i)
{
	if (flag->precision == 1 && flag->p_width == 0 && flag->left)
	{
		i = flag->width - 2;
		flag->result += i > 0 ? i + 1 : 0 + 1;
		write(1, "0x", 2);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		i = flag->width - 2;
		flag->result += i > 0 ? i + 1 : 0 + 1;
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "0x", 2);
	}
}

void			get_p(t_flag *flag, va_list ap)
{
	long long int	p;
	int				p_i;
	char			*str;

	p = va_arg(ap, long long int);
	str = ft_itoa_base_lower(p, 16);
	p_i = 0;
	flag->result += ft_strlen(str);
	if (p < 0)
	{
		get_md(flag, (p * -1), 0, p_i);
		return ;
	}
	if (flag->precision && p == 0 && flag->p_width <= 0)
		p_error_check(flag, 0);
	else if (flag->left)
		p_left_check(flag, p, 0, p_i);
	else if (flag->zero)
		p_zero_check(flag, p, 0, p_i);
	else if (flag->precision)
		p_pre_check(flag, p, 0, p_i);
	else
		p_last_check(flag, p, 0);
	free(str);
}
