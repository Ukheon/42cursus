/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:22:44 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/30 16:02:08 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <unistd.h>

// void		res(t_flag *flag)
// {
// 	flag->width = 5;
// }

// void		reset_flag(t_flag *flag)
// {
// 	flag->width = 0;
// 	res(flag);
// }

// void		chk(va_list ap)
// {
// 	printf("2 %d\n",va_arg(ap, int));
// }

// void		check_check(va_list ap)
// {
// 	printf("1 %d\n",va_arg(ap, int));
// 	chk(ap);
// }
// void		check_va(int a, ...)
// {
// 	va_list ap;

// 	va_start(ap, a);
// 	printf("%d\n",va_arg(ap, int));
// 	printf("%d\n",va_arg(ap, int));
// 	printf("%d\n",va_arg(ap, int));
// 	check_check(ap);
// 	// printf("%d\n",va_arg(ap, int));

// }
#include <stdio.h>
int			main(void)
{
	char *str = "";

	str = NULL;

	printf("%s\n",str);
}
