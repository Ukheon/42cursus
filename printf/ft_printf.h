/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:42:29 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/27 20:59:20 by ukwon            ###   ########.fr       */
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
	int			fill_zero;
	int			p_width;
	int			precision;
}				t_flag;

int				ft_printf(const char *format, ...);
char			*ft_itoa(int n);
static char		*putstr(char *res, int n, int len);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_strlen(char *str);
void			reset_flag(t_flag *flag);



#endif
