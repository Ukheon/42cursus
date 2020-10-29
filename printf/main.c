/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukheon <ukheon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:47:15 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/30 02:17:24 by ukheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// d_main

int			main(void)
{
	int i, j;
	char *str;
	int result1;
	int result2;

	i = -1512;
	printf("      printf -> :[%5d] [%5.10d] [%8.6d] [%-5.10d] [%-8.5d] [%-*.*d] [%d] [%08.15d] [%010.6d]\n", i, i, i, i,8, 10 , 8, i,i,i,i);
	ft_printf("   ft_printf -> :[%5d] [%5.10d] [%8.6d] [%-5.10d] [%-8.5d] [%-*.*d] [%d] [%08.15d] [%010.6d]\n", i, i, i, i, 8, 10 , 8, i,i,i,i);
	printf("      printf -> :[%-6d] [%-.15d] [%05.8d] [%0.3d] [%010d] [%-*.*d] [%.7d] [%6d]\n",i, i, i, i,8, 10 , 8, i,i,i);
	ft_printf("   ft_printf -> :[%-6d] [%-.15d] [%05.8d] [%0.3d] [%010d] [%-*.*d] [%.7d] [%6d]\n",i, i, i, i, 8, 10 , 8, i,i,i);
	printf("      printf -> :[%5.0d] [%10.9d] [%9.10d] [%-5.5d] [%-7.6d] [%-4.5d] [%08.8d] [%07.8d] [%08.7d] [%5.6d]\n",i,i,i,i,i,i,i,i,i,i);
	ft_printf("   ft_printf -> :[%5.0d] [%10.9d] [%9.10d] [%-5.5d] [%-7.6d] [%-4.5d] [%08.8d] [%07.8d] [%08.7d] [%5.6d]\n",i,i,i,i,i,i,i,i,i,i);

	printf("      printf -> :[%5.0d], [%.0d], [%5.d], [%-5.0d], [%-5.d] [%.d]\n", i,i,i,i,i,i);
	ft_printf("   ft_printf -> :[%5.0d], [%.0d], [%5.d], [%-5.0d], [%-5.d] [%.d]\n", i,i,i,i,i,i);

	result1 = printf("      printf -> :[%5d] [%5.10d] [%8.6d] [%-5.10d] [%-8.5d] [%-*.*d] [%d] [%08.15d] [%010.6d]\n", i, i, i, i,8, 10 , 8, i,i,i,i);
	result2 = ft_printf("   ft_printf -> :[%5d] [%5.10d] [%8.6d] [%-5.10d] [%-8.5d] [%-*.*d] [%d] [%08.15d] [%010.6d]\n", i, i, i, i, 8, 10 , 8, i,i,i,i);
	result1 = printf("      printf -> :[%5.0d], [%.0d], [%5.d], [%-5.0d], [%-5.d] [%.d]\n", i,i,i,i,i,i);
	result2 = ft_printf("   ft_printf -> :[%5.0d], [%.0d], [%5.d], [%-5.0d], [%-5.d] [%.d]\n", i,i,i,i,i,i);

	printf("result1 : %d\nresult2 : %d\n", result1, result2);
	return (0);
}

// c_main

// int			main(void)
// {
// 	char *s = "hello world";

// 	printf("   printf -> [%8s]\n",s);
// 	ft_printf("ft_printf -> [%8s]\n",s);
// }
