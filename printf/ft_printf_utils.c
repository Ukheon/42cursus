/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukheon <ukheon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:58:03 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/30 00:16:26 by ukheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			reset_flag(t_flag *flag)
{
	flag->width = 0;
	flag->zero = 0;
	flag->left = 0;
	flag->p_width = 0;
	flag->precision = 0;
	flag->check = 0;
}

void			ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	if (fd < 0)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void			ft_putchar_fd(char c, int fd)
{
	unsigned char	c1;

	c1 = (unsigned char)c;
	if (fd < 0)
		return ;
	write(fd, &c1, 1);
}
