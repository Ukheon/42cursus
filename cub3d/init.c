/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2020/12/02 17:10:40 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// 확인용 맵
int color = 0x00ff00;

int		map[11][11] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};

// int		map[11][11] = {
// 		{1,1,1,1,1,1,1,1,1,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,1,1,1,1,1,1,1,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,1,1,1,1,1,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,1,1,1,1,1,1,1,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,1,1,1,1,1,1,1,1,1}
// };

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
	int			count;
	int			index;

	float		p_x;
	float		p_y;
	float		pdr;
	float		x;
	float		y;
	float		len;

// img
	void		*img;
	int			*img_ptr;
	int			bpp;
	int			size_l;
	int			endian;
}				t_zip;

void	zip_setting(t_zip *zip)
{
	zip->width = 600;
	zip->height = 600;
	zip->p_x = 150;
	zip->p_y = 150;
	zip->pdr = 270;
	zip->count = 1;
	zip->index = 0;
}

void	show_cub(t_zip *zip)
{
	int		half;
	int		len;
	int		start;
	int		end;
	int		i;
	int		line;
	int		imgwidth;
	int		imgheight;
	int		save;
	int		zero;
	int		last;

	zero = 0;
	last = zip->height;
	line = (int)(zip->height) * 40 / (zip->len);

	//width = 600; sight = 61개의 광선을 쏠 때 10번 이다
	i = 0;
	while (zip->index < (zip->count * (zip->width / 60)))
	{
		start = -line / 2 + zip->height / 2;
		if (start < 0)
			start = 0;
		end = line / 2 + zip->height / 2;
		if (end >= zip->height)
			end = zip->height - 1;
		zero = 0;
		while (zero <= start)
		{
			zip->img_ptr[(zip->width) * zero + zip->index] = 0x00FF00;
			zero++;
		}
		while (start <= end)
		{
			zip->img_ptr[(zip->width) * start + zip->index] = 0xFF0000;
			start++;
		}
		while (start <= last)
		{
			zip->img_ptr[(zip->width) * start + zip->index] = 0xFFFFFF;
			start++;
		}
		mlx_put_image_to_window(zip->start, zip->win, zip->img, zip->index, 0);
		// while (start < end)
		// {
		// 	mlx_pixel_put(zip->start, zip->win, zip->index, start, 0xff0000);
		// 	start++;
		// }
		// zip->img = mlx_xpm_file_to_image(zip->start, "textures/wall_n.xpm", &imgwidth, &imgheight);
		// mlx_put_image_to_window(zip->start, zip->win, zip->img, zip->index, start);
		zip->index++;
	}
	zip->count++;
}

void	show_player(t_zip *zip)
{
	int		i;
	int		j;
	int		sight;
	float	a;
	float	b;

	// 플레이어 그리기
	// i = -5;
	// while (i < 5)
	// {
	// 	j = -5;
	// 	while (j < 5)
	// 	{
	// 		mlx_pixel_put(zip->start, zip->win, zip->p_x + i, zip->p_y + j, 0xff00ff);
	// 		j++;
	// 	}
	// 	i++;
	// }

	sight = -30;
	// mlx_clear_window(zip->start, zip->win);
	zip->count = 1;
	while (sight <= 30)
	{
		j = 0;
		while (++j)
		{
			zip->x = j * cos((zip->pdr + sight) * RAD) + zip->p_x;
			zip->y = j * sin((zip->pdr + sight) * RAD) + zip->p_y;

			// 광선 그리기
			// mlx_pixel_put(zip->start, zip->win, zip->x, zip->y, 0xff00ff);

			if (map[(int)(zip->y / (zip->height / 10))][(int)(zip->x / (zip->width / 10))] == 1)
			{
				a =	fabs(zip->p_x - zip->x);
				b =	fabs(zip->p_y - zip->y);

				// a & b 길이를 구해서 빗변=광선길이 구하기 # cos 붙는 이유는 내가보는 방향의 수직거리만 필요하기때문. 직각의 길이가 아니면 둥글게 나옴.
				zip->len = sqrt((a * a) + (b * b)) * cos(sight * RAD);
				show_cub(zip);
				// mlx_put_image_to_window(zip->start, zip->win, zip->img, zip->index, 0);
				continue;
			}
			if ((zip->x >= zip->width || zip->x <= 0) || (zip->y <= 0 || zip->y >= zip->height))
				break;
		}
		sight += 1;
	}
	zip->index = 0;
}

int		player_move(int keycode, t_zip *zip)
{
	float x_temp;
	float y_temp;


	if (keycode == W)
	{
		x_temp = zip->p_x + cos(zip->pdr * RAD) * 5;
		y_temp = zip->p_y + sin(zip->pdr * RAD) * 5;
		if (map[(int)(y_temp / (zip->height / 10))][(int)(x_temp / (zip->width / 10))] == 1)
			return (0);
		zip->p_x = x_temp;
		zip->p_y = y_temp;
	}
	if (keycode == S)
	{
		x_temp = zip->p_x - cos(zip->pdr * RAD) * 5;
		y_temp = zip->p_y - sin(zip->pdr * RAD) * 5;
		if (map[(int)(y_temp / (zip->height / 10))][(int)(x_temp / (zip->width / 10))] == 1)
			return (0);
		zip->p_x = x_temp;
		zip->p_y = y_temp;
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
	// printf("x : %f ",zip->p_x);
	// printf("// y : %f\n",zip->p_y);

	// show_player(zip);
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
	while (x < zip->height / 10)
	{
		y = 0;
		while (y < zip->width)
		{
			mlx_pixel_put(zip->start, zip->win, y, x * zip->height / 10, 0xff0000);
			y++;
		}
		x++;
	}
}

int		show_wall(t_zip *zip)
{
	int		i;
	int		j;

	mlx_clear_window(zip->start, zip->win);
	// i = 0;
	// while (i <= 10)
	// {
	// 	j = 0;
	// 	while (j <= 10)
	// 	{
	// 		if (map[i][j] == 1)
	// 			mlx_put_image_to_window(zip->start, zip->win, zip->img, (j * (zip->width / 10)), (i * (zip->height / 10)));
	// 		j++;
	// 	}
	// 	i++;
	// }
	// // show_grid(zip);
	show_player(zip);
	return (0);
}

// void	make_img(t_zip *zip)
// {
// 	int		width;
// 	int		height;
// 	int		i;

// 	i = 0;
// 	zip->img_ptr = (int *)mlx_get_data_addr(zip->img, &zip->bpp, &zip->size_l, &zip->endian);
// 	width = 0;
// 	while (width < zip->width/10)
// 	{
// 		height = 0;
// 		while (height < zip->width/10)
// 		{
// 			zip->img_ptr[i] = 0xffffff;
// 			height++;
// 			i++;
// 		}
// 		width++;
// 	}
// }

int		main(void)
{
	t_zip zip;
	int	imgwidth;
	int	imgheight;

	zip_setting(&zip);
	zip.start = mlx_init();
	zip.win = mlx_new_window(zip.start, zip.width, zip.height, "hi~hello");
	zip.img = mlx_new_image(zip.start, (zip.width), (zip.height));
	zip.img_ptr = (int *)mlx_get_data_addr(zip.img, &zip.bpp, &zip.size_l, &zip.endian);
	// zip.img = mlx_xpm_file_to_image(zip.start, "textures/wall_n.xpm", &imgwidth, &imgheight);
	// make_img(&zip);
	mlx_loop_hook(zip.start, &show_wall, &zip);
	//mlx_hook(zip.start, 2, 0, &show_wall, &zip);

	mlx_hook(zip.win, 2, 0, &player_move, &zip);
	mlx_loop(zip.start);
}
