/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:42:29 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/01 21:46:34 by ukwon            ###   ########.fr       */
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
	int			x_check;
}				t_flag;

void			x_zero_check(t_flag *flag, long long int p, int i, int p_i);
void			x_left_check(t_flag *flag, long long int p, int i, int p_i);
void			last_check(t_flag *flag, long long int p, int i);
void			check_precision(t_flag *flag, long long int p, int i, int p_i);
void			check_zero(t_flag *flag, long long int p, int i, int p_i);
void			check_left(t_flag *flag, long long int p, int i, int p_i);
char			*ft_itoa_base_upper(long long int value, int base);
char			*ft_itoa_base_lower(long long int value, int base);
void			null_s(t_flag *flag);
void			get_s(t_flag *flag, va_list ap);
void			get_per(t_flag *flag);
void			get_u(t_flag *flag, va_list ap);
void			get_p(t_flag *flag, va_list ap);
void			get_c(t_flag *flag, va_list ap);
void			get_x(t_flag *flag, va_list ap);
void			get_md(t_flag *flag, long long int p, int i, int p_i);
void			get_d(t_flag *flag, va_list ap);
int				ft_printf(const char *format, ...);
void			x_last_check(t_flag *flag, long long int p, int i);
void			reset_flag(t_flag *flag);

#endif
