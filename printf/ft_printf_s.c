/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:56:51 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/27 15:57:04 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
