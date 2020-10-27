/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:58:03 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/27 20:58:13 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			reset_flag(t_flag *flag)
{
	flag->width = 0;
	flag->fill_zero = 0;
	flag->left = 0;
	flag->p_width = 0;
	flag->precision = 0;
}
