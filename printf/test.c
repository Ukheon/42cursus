/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:22:44 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/27 20:00:19 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		res(t_flag *flag)
{
	flag->width = 5;
}

void		reset_flag(t_flag *flag)
{
	flag->width = 0;
	res(flag);
}

void		chk(va_list ap)
{
	printf("2 %d\n",va_arg(ap, int));
}

void		check_check(va_list ap)
{
	printf("1 %d\n",va_arg(ap, int));
	chk(ap);
}
void		check_va(int a, ...)
{
	va_list ap;

	va_start(ap, a);
	printf("%d\n",va_arg(ap, int));
	printf("%d\n",va_arg(ap, int));
	printf("%d\n",va_arg(ap, int));
	check_check(ap);
	// printf("%d\n",va_arg(ap, int));

}
int			main(void)
{
	t_flag flag;
	check_va(3, 6, 9, 12, 15, 18);
	flag.width = 10;
	printf("before : %d\n", flag.width);
	reset_flag(&flag);
	printf("after : %d\n", flag.width);
}
