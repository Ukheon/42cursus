/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:32:19 by Ukwon             #+#    #+#             */
/*   Updated: 2021/03/01 19:58:13 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	map_set(t_zip *zip, t_img *grid_img, t_grid *grid)
{
	grid->width = zip->width / 3;
	grid->height = zip->height / 3;
	grid->width_size = grid->width / (double)zip->width_size;
	grid->height_size = grid->height / (double)zip->height_size;
	grid_img->img = mlx_new_image(zip->mlx, grid->width, grid->height);
	grid_img->data = (int *)mlx_get_data_addr(grid_img->img, \
	&grid_img->bpp, &grid_img->size_l, &grid_img->endian);
	grid->i = -1;
	while (++grid->i < (int)grid->height && (grid->j = -1))
	{
		while (++grid->j < (int)grid->width)
		{
			if (zip->map[(int)(grid->i / grid->height_size)]\
			[(int)(grid->j / grid->width_size)] == '1')
				grid_img->data[(int)(grid->i * grid->width + \
				grid->j)] = 0x9900ffff;
			else if (zip->map[(int)(grid->i / grid->height_size)]\
			[(int)(grid->j / grid->width_size)] == '2')
				grid_img->data[(int)(grid->i * \
				grid->width + grid->j)] = 0x99ff0000;
			else
				grid_img->data[(int)(grid->i * \
				grid->width + grid->j)] = 0x99ffffff;
		}
	}
}

void		draw_map(t_zip *zip)
{
	t_img		grid_img;
	t_grid		grid;

	map_set(zip, &grid_img, &grid);
	grid.player_x = zip->player_x * grid.height_size;
	grid.player_y = zip->player_y * grid.width_size;
	grid.i = -3;
	while (++grid.i < 3 && (grid.j = -3))
		while (++grid.j < 3)
			grid_img.data[(int)((int)((grid.player_x) + grid.i) \
			* grid.width + (grid.player_y + grid.j))] = 0x000000;
	mlx_put_image_to_window(zip->mlx, zip->win, grid_img.img, 0, 0);
}
