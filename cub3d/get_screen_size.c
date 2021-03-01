/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:18:43 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/02 01:34:37 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include "./mlx2/mlx.h"
#include <stdio.h>

int			main(void)
{
	int w;
	int h;
	void *mlx;

	mlx = mlx_init();
	mlx_get_screen_size(mlx, &w, &h);
	printf("%d %d\n",w,h);
	return (0);
}
