/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:43:29 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/30 14:52:03 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int				check_flag(char format, t_flag *flag, va_list ap)
{
	if (format == '0' && flag->check == 0 && flag->zero == 0)
		flag->zero = 1;
	else if (flag->precision && format >= '0' && format <= '9')
		flag->p_width = (flag->p_width * 10) + (format - '0');
	else if (format >= '0' && format <= '9')
	{
		flag->width = (flag->width * 10) + (format - '0');
		flag->check = 1;
	}
	else if (format == '*')
	{
		if (flag->precision == 1)
			flag->p_width = va_arg(ap, int);
		else
			flag->width = va_arg(ap, int);
	}
	else if (format == '.')
		flag->precision = 1;
	else if (format >= '0' && format <= '9')
		flag->width = (flag->width * 10) + (format - '0');
	else if (format == '-')
		flag->left = 1;
	else
		return (0);
	return (1);
}

void			ft_start(const char **format, va_list ap, t_flag *flag)
{
	reset_flag(flag);
	while (**format)
	{
		if (check_flag((**format), flag, ap))
		{
			(*format)++;
			continue ;
		}
		else
			break ;
		(*format)++;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	t_flag	flag;

	va_start(ap, format);
	flag.result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, &(*format), 1);
				flag.result++;
			}
			ft_start(&format, ap, &flag);
			if (*format == 'd' || *format == 'i')
				get_d(&flag, ap);
			else if (*format == 'c')
				get_c(&flag, ap);
			else if (*format == 's')
				get_s(&flag, ap);
		}
		else
		{
			write(1, &(*format), 1);
			flag.result++;
		}
		format++;
	}
	return (flag.result);
}
