/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:13:42 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/24 22:41:08 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void			wall_set(t_zip *zip)
{
	if (zip->side == 0)
		zip->raylen = (zip->map_x - zip->player_x + (1 - zip->step_x) / 2) / zip->ray_dir_x;
	else
		zip->raylen = (zip->map_y - zip->player_y + (1 - zip->step_y) / 2) / zip->ray_dir_y;
	zip->line_height = (int)(zip->height / zip->raylen);
	zip->draw_start = -zip->line_height / 2 + zip->height / 2;
	if (zip->draw_start < 0)
		zip->draw_start = 0;
	zip->draw_end = zip->line_height / 2 + zip->height / 2;
	if (zip->draw_end >= zip->height)
		zip->draw_end = zip->height;
	if (zip->side == 1 && zip->ray_dir_y > 0)
		zip->text_num = 0;
	else if(zip->side == 1 && zip->ray_dir_y < 0)
		zip->text_num = 1;
	else if(zip->side == 0 && zip->ray_dir_x > 0)
		zip->text_num = 2;
	else
		zip->text_num = 3;
	if (zip->side == 1)
		zip->wall = zip->player_x + zip->raylen * zip->ray_dir_x;
	else
		zip->wall = zip->player_y + zip->raylen * zip->ray_dir_y;
}

static void			dda_init(t_zip *zip, int x, int y)
{
	zip->camera = 2 * x / (double)zip->width - 1;
	zip->ray_dir_x = zip->dir_x + zip->plane_x * zip->camera;
	zip->ray_dir_y = zip->dir_y + zip->plane_y * zip->camera;
	zip->map_x = (int)zip->player_x;
	zip->map_y = (int)zip->player_y;
	zip->delta_x = fabs(1 / zip->ray_dir_x);
	zip->delta_y = fabs(1 / zip->ray_dir_y);
}

static void			ray_set(t_zip *zip)
{
	if (zip->ray_dir_x < 0 && (zip->step_x = -1))
			zip->side_dist_x = (zip->player_x - zip->map_x) * zip->delta_x;
	else if ((zip->step_x = 1))
		zip->side_dist_x = (zip->map_x + 1.0 - zip->player_x) * zip->delta_x;
	if (zip->ray_dir_y < 0 && (zip->step_y = -1))
		zip->side_dist_y = (zip->player_y - zip->map_y) * zip->delta_y;
	else if ((zip->step_y = 1))
		zip->side_dist_y = (zip->map_y + 1.0 - zip->player_y) * zip->delta_y;
	zip->hit = 0;
	while (zip->hit == 0)
	{
		if (zip->side_dist_x < zip->side_dist_y)
		{
			zip->side_dist_x += zip->delta_x;
			zip->map_x += zip->step_x;
			zip->side = 0;
		}
		else
		{
			zip->side_dist_y += zip->delta_y;
			zip->map_y += zip->step_y;
			zip->side = 1;
		}
		if (zip->map[zip->map_x][zip->map_y] == '1')
			zip->hit = 1;
	}
}

void			dda(t_zip *zip, int x, int y)
{
	while (++x < zip->width)
	{
		dda_init(zip ,x ,y);
		ray_set(zip);
		wall_set(zip);
		zip->wall -= floor(zip->wall);
		zip->text_x = (int)(zip->wall * (double)text_width);
		if (zip->side == 0 && zip->ray_dir_x > 0)
			zip->text_x = text_width - zip->text_x - 1;
		if (zip->side == 1 && zip->ray_dir_y < 0)
			zip->text_x = text_width - zip->text_x - 1;
		zip->text_step = (double)text_width / zip->line_height;
		zip->text_pos = (zip->draw_start - zip->height / 2 + zip->line_height / 2) * zip->text_step;
		y = zip->draw_start - 1;
		while (++y < zip->draw_end)
		{
			zip->text_y = (int)zip->text_pos;
			zip->text_pos += zip->text_step;
			zip->buf[y][x] = zip->texture[zip->text_num][text_height * zip->text_y + zip->text_x];
		}
		zip->save_wall_len[x] = zip->raylen;
	}
}

void		calc(t_zip *zip, int x, int y)
{
	while (++y < zip->height && (x = -1))
	{
		x = -1;
		while (++x < zip->width)
		{
			if (y < zip->height / 2)
				zip->buf[y][x] = zip->c_color;
			else
				zip->buf[y][x] = zip->f_color;
		}
	}
	dda(zip, -1, y);
	x = -1;
	while (++x < zip->count_sprite)
	{
		zip->sprite[x].len = ((zip->player_x - zip->sprite[x].x) * (zip->player_x - zip->sprite[x].x)) +
		((zip->player_y - zip->sprite[x].y) * (zip->player_y - zip->sprite[x].y));
	}
	sort_sprite(zip);
	x = -1;
	while (++x < zip->count_sprite)
	{
		zip->relative_x = zip->sprite[x].x - zip->player_x;
		zip->relative_y = zip->sprite[x].y - zip->player_y;
		zip->sub = 1.0 / (zip->plane_x * zip->dir_y - zip->dir_x * zip->plane_y);
		zip->transform_x = zip->sub * (zip->dir_y * zip->relative_x - zip->dir_x * zip->relative_y);
		zip->transform_y = zip->sub * (-zip->plane_y * zip->relative_x + zip->plane_x * zip->relative_y);
		zip->sprite_screen = (int)((zip->width / 2) * (1 + zip->transform_x / zip->transform_y));
		zip->sprite_height = (int)fabs((zip->height / zip->transform_y));
		zip->sprite_width = (int)fabs((zip->width / zip->transform_y));
		zip->sprite_start_x = -zip->sprite_width / 2 + zip->sprite_screen;
		if (zip->sprite_start_x < 0)
			zip->sprite_start_x = 0;
		zip->sprite_end_x = zip->sprite_width / 2 + zip->sprite_screen;
		if (zip->sprite_end_x > zip->width)
			zip->sprite_end_x = zip->width;
		zip->sprite_end_y = zip->sprite_height / 2 + zip->height / 2;
		if (zip->sprite_end_y >= zip->height)
			zip->sprite_end_y = zip->height;
		while (zip->sprite_start_x < zip->sprite_end_x)
		{
			zip->text_x = (int)((256 * (zip->sprite_start_x - (-zip->sprite_width / 2 + zip->sprite_screen)) * text_width / zip->sprite_width) / 256);
			if (zip->transform_y > 0 && zip->sprite_start_x > 0 && zip->sprite_start_x < zip->width && zip->transform_y < zip->save_wall_len[zip->sprite_start_x])
			{
				zip->sprite_start_y = -(zip->sprite_height / 2) + zip->height / 2;
				if (zip->sprite_start_y < 0)
					zip->sprite_start_y = 0;
				while (zip->sprite_start_y < zip->sprite_end_y)
				{
					zip->sub = (zip->sprite_start_y) * 256 - zip->height * 128 + zip->sprite_height * 128;
					zip->text_y = ((zip->sub * text_height) / zip->sprite_height) / 256;

					zip->color = zip->texture[4][text_width * zip->text_y + zip->text_x];
					if (zip->color != 0)
						zip->buf[zip->sprite_start_y][zip->sprite_start_x] = zip->color;
					zip->sprite_start_y++;
				}
			}
			zip->sprite_start_x++;
		}
	}
}

