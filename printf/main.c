/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:47:15 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/03 21:13:55 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// d_main

int			main(void)
{
	int i;
	char *s;
	int result1;
	int result2;
	char c = 'y';
	s = "";
	i = 12345;
	int j;
	j = 8;
	int l;
	l = 64;
	int k;
	k = 0;
	// printf("%s", NULL);

	// result1 = printf("[%-p]\n",&s);
	// result2 = ft_printf("[%-p]\n",&s);
	// result1 = printf("[%.s] [%-.4s] [%5.3s] [%-4.8s] [%8.10s] [%-10.s]\n",s,s,s,s,s,s);
	// result2 = ft_printf("[%.s] [%-.4s] [%5.3s] [%-4.8s] [%8.10s] [%-10.s]\n",s,s,s,s,s,s);
	// result1 = printf("[%c] [%2c] [%3c] [%-7c]\n",c,c,c,c);
	// result2 = ft_printf("[%c] [%2c] [%3c] [%-7c]\n",c,c,c,c);
	// result1 = printf("%-.c%-2.c%-3.c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
	// result2 = ft_printf("%-.c%-2.c%-3.c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
	// result1 = printf("[%-*.*i], [%-*.*d], [%-*.*d], [%-*.*d], [%-*.*d], [%-*.*d], [%-*.*d], [%-*.*d]\n",-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i);
	// result2 = ft_printf("[%-*.*i], [%-*.*d], [%-*.*d], [%-*.*d], [%-*.*d], [%-*.*d], [%-*.*d], [%-*.*d]\n",-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i,-1,-1,i);

	// result1 = printf("[%X] [%5X] [%.5X] [%-5.10X] [%2.5X]\n", i,i,i,i,i);
	// result2 = ft_printf("[%X] [%5X] [%.5X] [%-5.10X] [%2.5X]\n", i,i,i,i,i);

	// result1 = printf("[%-5u] [%5u] [%.5u] [%-5.10u] [%2.5u]\n", i,i,i,i,i);
	// result2 = ft_printf("[%-5u] [%5u] [%.5u] [%-5.10u] [%2.5u]\n", i,i,i,i,i);
	// result1 = printf("[%-*p] [%-*p] [%-5p] [%-*p] [%*p] [%*p]\n",i,&i,i,&i,&i,i,&i,i,&i,i,&i);
	// result2 = ft_printf("[%-*p] [%-*p] [%-5p] [%-*p] [%*p] [%*p]\n",i,&i,i,&i,&i,i,&i,i,&i,i,&i);
	// result1 = printf("[%*x] [%*x] [%*x] [%*x] [%*x] [%*x]\n",k,k,k,k,k,k,k,k,k,k,k,k);
	// result2 = ft_printf("[%*x] [%*x] [%*x] [%*x] [%*x] [%*x]\n",k,k,k,k,k,k,k,k,k,k,k,k);
	// result1 = printf("[%-*p], [%010.*u], [%-*p], [%-*x], [%-*p], [%-*x], [%-*p], [%-*x]\n", k,&i,k,k,k,&j,k,k,k,&l,k,k,k,&i,k,i);
	// result2 = ft_printf("[%-*p], [%010.*u], [%-*p], [%-*x], [%-*p], [%-*x], [%-*p], [%-*x]\n", k,&i,k,k,k,&j,k,k,k,&l,k,k,k,&i,k,i);
	// result1 = printf("[%x] [%X] [%.10x] [%.x] [%.X] [%.10X]\n",i,i,i,i,i,i);
	// result2 = ft_printf("[%x] [%X] [%.10x] [%.x] [%.X] [%.10X]\n",i,i,i,i,i,i);
	// result1 = printf("[%c],  [%-c], [%1c], [%*c],  [%-*c],  [%*c]\n",97,97,97,k,97,k,97,k,97);
	// result2 = ft_printf("[%c],  [%-c], [%1c], [%*c],  [%-*c],  [%*c]\n",97,97,97,k,97,k,97,k,97);
	// result1 = printf("[%-10.5s][%20.5s][%5.10s]\n",NULL, NULL, NULL);
	// result2 = ft_printf("[%-10.5s][%20.5s][%5.10s]\n",NULL, NULL, NULL);
	// printf("result1 : %d\nresult2 : %d\n", result1, result2);
	// printf("      printf -> :[%*.5d] [%5.10d] [%8.6d] [%-5.10d] [%-8.5d] [%-*.*d] [%d] [%08.15d] [%010.6d]\n",-5, i, i, i, i,8, 10 , 8, i,i,i,i);
	// ft_printf("   ft_printf -> :[%*.5d] [%5.10d] [%8.6d] [%-5.10d] [%-8.5d] [%-*.*d] [%d] [%08.15d] [%010.6d]\n",-5, i, i, i, i, 8, 10 , 8, i,i,i,i);
	// printf("      printf -> :[%-6d] [%-.15d] [%05.8d] [%0.3d] [%010d] [%-*.*d] [%.7d] [%6d]\n",i, i, i, i,8, 10 , 8, i,i,i);
	// ft_printf("   ft_printf -> :[%-6d] [%-.15d] [%05.8d] [%0.3d] [%010d] [%-*.*d] [%.7d] [%6d]\n",i, i, i, i, 8, 10 , 8, i,i,i);
	// printf("      printf -> :[%5.0d] [%10.9d] [%9.10d] [%-5.5d] [%-7.6d] [%-4.5d] [%08.8d] [%07.8d] [%08.7d] [%5.6d]\n",i,i,i,i,i,i,i,i,i,i);
	// ft_printf("   ft_printf -> :[%5.0d] [%10.9d] [%9.10d] [%-5.5d] [%-7.6d] [%-4.5d] [%08.8d] [%07.8d] [%08.7d] [%5.6d]\n",i,i,i,i,i,i,i,i,i,i);

	// printf("      printf -> :[%5.0d], [%.0d], [%5.d], [%-5.0d], [%-5.d] [%.d]\n", i,i,i,i,i,i);
	// ft_printf("   ft_printf -> :[%5.0d], [%.0d], [%5.d], [%-5.0d], [%-5.d] [%.d]\n", i,i,i,i,i,i);

	// result1 = printf("      printf -> :[%5u] [%5.10u] [%8.6d] [%-5.10d] [%-8.5d] [%-*.*d] [%d] [%08.15d] [%010.6d]\n", i, i, i, i,8, 10 , 8, i,i,i,i);
	// result2 = ft_printf("   ft_printf -> :[%5u] [%5.10u] [%8.6d] [%-5.10d] [%-8.5d] [%-*.*d] [%d] [%08.15d] [%010.6d]\n", i, i, i, i, 8, 10 , 8, i,i,i,i);
	// result1 = printf("      printf -> :[%5.0d], [%.0d], [%5.d], [%-5.0d], [%-5.d] [%.d]\n", i,i,i,i,i,i);
	// result2 = ft_printf("   ft_printf -> :[%5.0d], [%.0d], [%5.d], [%-5.0d], [%-5.d] [%.d]\n", i,i,i,i,i,i);

	// printf("result1 : %d\nresult2 : %d\n", result1, result2);
	// return (0);
// }
	ft_printf("%d", 1);
	while (1)
		;
	return (0);
}

// c_main

// int			main(void)
// {
// 	char *i;

// 	i = "abc";
// 	printf("   printf -> [%*s]\n",-32, i);
// 	ft_printf("   ft_printf -> [%*s]\n",-32, i);
// }
