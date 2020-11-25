/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2020/11/25 17:26:38 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// 확인용 맵

int		map[11][11] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};

#define A 0
#define S 1
#define D 2
#define W 13
#define END 53
#define PI 3.14159265359
#define RAD PI/180

typedef struct	s_zip
{
	void		*start;
	void		*win;
	int			width;
	int			height;
	float		p_x;
	float		p_y;
	float		pdr;


// img
	void		*img;
	int			*img_ptr;
	int			bits;
	int			size_l;
	int			endian;
}				t_zip;

void	zip_setting(t_zip *zip)
{
	zip->width = 600;
	zip->height = 600;
	zip->p_x = 200;
	zip->p_y = 200;
	zip->pdr = 270;
}

void	show_player(t_zip *zip)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		sight;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			mlx_pixel_put(zip->start, zip->win, cos(zip->pdr * RAD) + zip->p_x + i, sin(zip->pdr * RAD) + zip->p_y + j, 0xff00ff);
			j++;
		}
		i++;
	}

	sight = -15;
	while (sight < 15)
	{
		j = 0;
		while (++j)
		{
			x = j * cos((zip->pdr + sight) * RAD) + zip->p_x;
			y = j * sin((zip->pdr + sight) * RAD) + zip->p_y;
			mlx_pixel_put(zip->start, zip->win, x, y, 0xff00ff);
			printf("%d\n",j);
			if ((x >= zip->width || x <= 0) || (y <= 0 || y >= zip->height))
				break;
		}
		sight += 5;
	}
}

int		player_move(int keycode, t_zip *zip)
{
	if (keycode == W)
	{
		zip->p_x += cos(zip->pdr * RAD) * 5;
		zip->p_y += sin(zip->pdr * RAD) * 5;
	}
	if (keycode == S)
	{
		zip->p_x -= cos(zip->pdr * RAD) * 5;
		zip->p_y -= sin(zip->pdr * RAD) * 5;
	}
	if (keycode == A)
	{
		zip->pdr -= 5;
		if (zip->pdr <= 0)
			zip->pdr = 355;
	}
	if (keycode == D)
	{
		zip->pdr += 5;
		if (zip->pdr >= 360)
			zip->pdr = 5;
	}
	if (keycode == END)
		exit(0);
	return (0);
}

void	show_grid(t_zip *zip)
{
	int		x;
	int		y;

	x = 0;
	while (x < zip->width / 10)
	{
		y = 0;
		while (y < zip->height)
		{
			mlx_pixel_put(zip->start, zip->win, x * zip->width / 10, y, 0xff0000);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < zip->width / 10)
	{
		y = 0;
		while (y < zip->height)
		{
			mlx_pixel_put(zip->start, zip->win, y, x * zip->width / 10, 0xff0000);
			y++;
		}
		x++;
	}
}

int		show_wall(t_zip *zip)
{
	mlx_clear_window(zip->start, zip->win);
	mlx_put_image_to_window(zip->start, zip->win, zip->img, 0, 0);
	show_grid(zip);
	show_player(zip);
	return (0);
}

void	make_img(t_zip *zip)
{
	int		width;
	int		height;
	int		i;

	i = 0;
	zip->img_ptr = (int *)mlx_get_data_addr(zip->img, &zip->bits, &zip->size_l, &zip->endian);
	width = 0;
	while (width < zip->width/10)
	{
		height = 0;
		while (height < zip->width/10)
		{
			zip->img_ptr[width * zip->width/10 + height] = 0xffffff;
			height++;
		}
		width++;
	}
}

int		main(void)
{
	t_zip zip;

	zip_setting(&zip);
	zip.start = mlx_init();
	zip.win = mlx_new_window(zip.start, zip.width, zip.height, "hi~hello");
	zip.img = mlx_new_image(zip.start, (zip.width / 10), (zip.height / 10));
	make_img(&zip);
	mlx_loop_hook(zip.start, &show_wall, &zip);
	mlx_hook(zip.win, 2, 0, &player_move, &zip);
	mlx_loop(zip.start);
}
