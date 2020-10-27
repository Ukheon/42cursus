/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:43:29 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/27 21:26:13 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			get_d(t_flag *flag, va_list ap)
{
	int save;
	int i;

	save = va_arg(ap, int);
	if (flag->left == 1)
	{
		ft_putstr_fd((ft_itoa(save)), 1);
		i = flag->width - ft_strlen(ft_itoa(save));
		while (i--)
			write(1, " ", 1);
	}
	else if (flag->fill_zero == 1)
	{
		i = flag->width - ft_strlen(ft_itoa(save));
		while (i--)
			write(1, "0", 1);
		ft_putstr_fd((ft_itoa(save)), 1);
	}
	else
		ft_putstr_fd((ft_itoa(save)), 1);
}

int				check_flag(char format, t_flag *flag, va_list ap)
{
	if (format == '-')
		flag->left = 1;
	else if (format == '*' && flag->precision == 1)
		flag->p_width = va_arg(ap, int);
	else if (format == '*' && (flag->left == 1 || flag->fill_zero == 1))
		flag->width = va_arg(ap, int);
	else if (format == '.')
		flag->precision = 1;
	else if ((flag->left == 1 || flag->fill_zero == 1) &&\
		(format >= '0' && format <= '9'))
		flag->width = (flag->width * 10) + (format - 48);
	else if (format == '0')
		flag->fill_zero = 1;
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
	int		res;

	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_start(&format, ap, &flag);
			if (*format == 'd')
				get_d(&flag, ap);
			else if (*format == 's')
				ft_putstr_fd(va_arg(ap, char*), 1);
		}
		else
		{
			write(1, &(*format), 1);
			res++;
		}
		format++;
	}
	return (res);
}
