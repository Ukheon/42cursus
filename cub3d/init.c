/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2020/12/04 17:09:48 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// 확인용 맵
int color = 0x00ff00;

// int		map[11][11] = {
// 		{1,1,1,1,1,1,1,1,1,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,0,1,0,0,0,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,1},
// 		{1,1,1,1,1,1,1,1,1,1}
// };

int		map[11][11] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};

#define A 0
#define S 1
#define D 2
#define W 13
#define END 53
#define PI 3.1415926535897932
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
	int			*texture;
	int			*img_ptr;
	int			bpp;
	int			size_l;
	int			endian;
}				t_zip;


void	zip_setting(t_zip *zip)
{
	zip->width = 600;
	zip->height = 600;
	zip->p_x = 120;
	zip->p_y = 230;
	zip->pdr = 270;
	zip->count = 1;
	zip->index = 0;
}


void	show_cub(t_zip *zip)
{
	float	start;
	float	end;
	float	line;
	float	zero;
	float	last;

	line = (float)((zip->height) * 40 / (zip->len));

	//width = 600; sight = 61개의 광선을 쏠 때 10번 이다

	start = -line / 2 + zip->height / 2;
	if (start < 0)
		start = 0;
	end = line / 2 + zip->height / 2;
	if (end >= zip->height)
		end = zip->height;
	zero = 0;
	while (zero < start)
	{
		zip->img_ptr[(int)zero * zip->width + zip->index] = 0x00ff00;
		// mlx_pixel_put(zip->start, zip->win, zip->index, zero, 0x00ff00);
		// zip->img_ptr[(int)(zip->width) * (int)(zero) + zip->index] = \
		// zip->texture[(int)((zip->width) * (int)zero + zip->index) / 10];
		zero++;
	}
	int check_point = 0;
	int	count = 0;
	int check_po1;

	check_po1 = (int)end - (int)start / 64;
	if (((int)end - (int)start % 64) > 32)
		check_po1++;
	while (start < end)
	{
		if (count != 0 && count % check_po1 == 0)
		{
			count = 0;
			check_point++;
		}
		zip->img_ptr[(int)start * zip->width + zip->index] = zip->texture[64 * check_point + ((int)zip->len + (int)zip->index) % 64];
		// mlx_pixel_put(zip->start, zip->win, zip->index, start, 0xff00ff);
		// zip->img_ptr[(int)(zip->width) * (int)start + zip->index] = \
		// zip->texture[(int)((zip->width) * (int)start + zip->index) / 10];
		count++;
		start++;
	}
	while (start <= zip->height)
	{
		zip->img_ptr[(int)start * zip->width + zip->index] = 0xffffff;
		// mlx_pixel_put(zip->start, zip->wn, zip->index, start, 0x0000ff);
		// zip->img_ptr[(int)(zip->width) * (int)start + zip->index] = \
		// zip->texture[(int)((zip->width) * (int)start + zip->index) / 10];
		// mlx_pixel_put(zip->start, zip->win, (int)start, zip->index, 0x0000ff);
		start++;
	}
	// mlx_put_image_to_window(zip->start, zip->win, zip->img, 0, 0);
	
	// mlx_put_image_to_window(zip->start, zip->win, zip->img, zip->index, 0);
	// while (start < end)
	// {
	// 	mlx_pixel_put(zip->start, zip->win, zip->index, start, 0xff0000);
	// 	start++;
	// }
	// zip->img = mlx_xpm_file_to_image(zip->start, "textures/wall_n.xpm", &imgwidth, &imgheight);
	// mlx_put_image_to_window(zip->start, zip->win, zip->img, zip->index, start);
	zip->index++;

	// mlx_put_image_to_window(zip->start, zip->win, zip->img, zip->index, 0);
	zip->count++;
}

void	show_player(t_zip *zip)
{
	int		i;
	float	j;
	float	sight;
	float	a;
	float	b;

	mlx_clear_window(zip->start, zip->win);
	sight = -33.0;
	while (sight <= 33.0)
	{
		j = 0;
		while (1)
		{
			zip->x = j * cos((zip->pdr + sight) * RAD) + zip->p_x;
			zip->y = j * sin((zip->pdr + sight) * RAD) + zip->p_y;

			if (map[(int)(zip->y / (zip->height / 10))][(int)(zip->x / (zip->width / 10))] == 1)
			{
				a =	abs((int)zip->p_x - (int)zip->x);
				b =	abs((int)zip->p_y - (int)zip->y);

				// a & b 길이를 구해서 빗변=광선길이 구하기 # cos 붙는 이유는 내가보는 방향의 수직거리만 필요하기때문. 직각의 길이가 아니면 둥글게 나옴.
				zip->len = sqrt((a * a) + (b * b)) * cos(sight * RAD);
				show_cub(zip);
				break;
			}
			j += 1.0;
			// if ((zip->x >= zip->width || zip->x <= 0) || (zip->y <= 0 || zip->y >= zip->height))
			// 	break;
		}
		sight += (66.0 / zip->width);
	}
	mlx_put_image_to_window(zip->start, zip->win, zip->img, 0, 0);

	// mlx_put_image_to_window(zip->start, zip->win, zip->img, 0, 0);

	zip->count = 1;
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
		zip->pdr -= 5.0;
		if (zip->pdr < 0)
			zip->pdr = 355.0;
	}
	if (keycode == D)
	{
		zip->pdr += 5.0;
		if (zip->pdr > 360)
			zip->pdr = 5.0;
	}
	if (keycode == END)
		exit(0);
	return (0);
}


void	load_image(t_zip *zip)
{
	int		img_height;
	int		img_width;
	int		x , y;


	zip->img = mlx_xpm_file_to_image(zip->start, "textures/eagle.xpm", &img_width, &img_height);
	zip->texture = (int *)malloc(sizeof(int) * ((img_width * img_height) + 1));
	zip->img_ptr = (int *)mlx_get_data_addr(zip->img, &zip->bpp, &zip->size_l, &zip->endian);

	y = 0;
	while (y < img_height)
	{
		x = 0;
		while (x < img_width)
		{
			zip->texture[img_width * y + x] = zip->img_ptr[img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(zip->start, zip->img);
	// mlx_put_image_to_window(zip->start,zip->win, zip->img_ptr, 0,0);
	// zip->img = mlx_new_image(zip->start, img_width, img_height);
	// zip->img_ptr = (int *)mlx_get_data_addr(zip->img, &zip->bpp, &zip->size_l, &zip->endian);
	// while (y < img_height)
	// {
	// 	x = 0;
	// 	while (x < img_width)
	// 	{
	// 		zip->img_ptr[img_width * y + x] = zip->texture[img_width * y + x];
	// 		x++;
	// 	}
	// 	y++;
	// }
	// mlx_put_image_to_window(zip->start,zip->win, zip->img, 0,0);
	// mlx_destroy_image(zip->start, zip->img);

}

int		show_wall(t_zip *zip)
{

	// mlx_clear_window(zip->start, zip->win);
	show_player(zip);
	return (0);
}

int		main(void)
{
	t_zip zip;
	int	imgwidth;
	int	imgheight;

	zip_setting(&zip);
	zip.start = mlx_init();
	zip.win = mlx_new_window(zip.start, zip.width, zip.height, "hi~hello");

	load_image(&zip);

	zip.img = mlx_new_image(zip.start, zip.width, zip.height);
	zip.img_ptr = (int *)mlx_get_data_addr(zip.img, &zip.bpp, &zip.size_l, &zip.endian);

	mlx_loop_hook(zip.start, &show_wall, &zip);
	mlx_hook(zip.win, 2, 0, &player_move, &zip);


	mlx_loop(zip.start);
}
