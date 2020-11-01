/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:42:29 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/01 19:10:46 by ukwon            ###   ########.fr       */
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
	int			width;
	int			left;
	int			zero;
	int			p_width;
	int			precision;
	int			check;
	int			result;
}				t_flag;

char			*ft_itoa_base_X(long long int value, int base);
char			*ft_itoa_base(long long int value, int base);
void			null_s(t_flag *flag);
void			get_s(t_flag *flag, va_list ap);
void			get_per(t_flag *flag);
void			get_u(t_flag *flag, va_list ap);
void			get_p(t_flag *flag, va_list ap);
void			get_c(t_flag *flag, va_list ap);
void			get_lower(t_flag *flag, va_list ap);
void			get_upper(t_flag *flag, va_list ap);
void			get_md(t_flag *flag, long long int p);
void			get_d(t_flag *flag, va_list ap);
int				ft_printf(const char *format, ...);
void			reset_flag(t_flag *flag);

#endif
