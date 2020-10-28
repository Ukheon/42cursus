/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:42:29 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/28 20:08:30 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flag
{
	// char		*format;
	int			width;
	int			left;
	int			zero;
	int			p_width;
	int			precision;
	int			check;
}				t_flag;

void			get_md(t_flag *flag, int p);
void			get_d(t_flag *flag, va_list ap);
int				ft_printf(const char *format, ...);
char			*ft_itoa(int n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_strlen(char *str);
void			reset_flag(t_flag *flag);

#endif
