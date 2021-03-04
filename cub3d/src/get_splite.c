/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_splite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:27:45 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/04 18:17:52 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		draw_sprite_y(t_zip *zip)
{
	while (zip->sprite_start_y < zip->sprite_end_y)
	{
		zip->sub = (zip->sprite_start_y) * 256 - zip->height * 128 +\
		zip->sprite_height * 128;
		zip->text_y = ((zip->sub * text_height) / zip->sprite_height)\
			/ 256;
		zip->color = zip->texture[4][text_width * zip->text_y + \
		zip->text_x];
		if (zip->color != 0)
			zip->buf[zip->sprite_start_y][zip->sprite_start_x] = zip->color;
		zip->sprite_start_y++;
	}
}

static void		draw_sprite_x(t_zip *zip)
{
	while (zip->sprite_start_x < zip->sprite_end_x)
	{
		zip->text_x = (int)((256 * (zip->sprite_start_x - \
		(-zip->sprite_width / 2 + zip->sprite_screen)) *\
		text_width / zip->sprite_width) / 256);
		if (zip->transform_y > 0 && zip->sprite_start_x > \
		0 && zip->sprite_start_x < zip->width && zip->transform_y\
		< zip->save_wall_len[zip->sprite_start_x])
		{
			zip->sprite_start_y = -(zip->sprite_height / 2) + zip->height / 2;
			if (zip->sprite_start_y < 0)
				zip->sprite_start_y = 0;
			draw_sprite_y(zip);
		}
		zip->sprite_start_x++;
	}
}

static void		set_sprite(t_zip *zip, int x)
{
	zip->relative_x = zip->sprite[x].x - zip->player_x;
	zip->relative_y = zip->sprite[x].y - zip->player_y;
	zip->sub = 1.0 / (zip->plane_x * zip->dir_y - zip->dir_x * zip->plane_y);
	zip->transform_x = zip->sub * (zip->dir_y * zip->relative_x - \
	zip->dir_x * zip->relative_y);
	zip->transform_y = zip->sub * (-zip->plane_y * zip->relative_x + \
	zip->plane_x * zip->relative_y);
	zip->sprite_screen = (int)((zip->width / 2) * (1 + zip->transform_x \
	/ zip->transform_y));
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
	draw_sprite_x(zip);
}

static void		sort_sprite(t_zip *zip)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = -1;
	while (++i < zip->count_sprite)
	{
		j = -1;
		while (++j < zip->count_sprite - 1)
		{
			if (zip->sprite[j].len < zip->sprite[j + 1].len)
			{
				tmp.x = zip->sprite[j].x;
				zip->sprite[j].x = zip->sprite[j + 1].x;
				zip->sprite[j + 1].x = tmp.x;
				tmp.y = zip->sprite[j].y;
				zip->sprite[j].y = zip->sprite[j + 1].y;
				zip->sprite[j + 1].y = tmp.y;
			}
		}
	}
}

void			get_sprite(t_zip *zip, int x)
{
	while (++x < zip->count_sprite)
	{
		zip->sprite[x].len = ((zip->player_x - zip->sprite[x].x) *\
		(zip->player_x - zip->sprite[x].x)) +
		((zip->player_y - zip->sprite[x].y) * (zip->player_y -\
		zip->sprite[x].y));
	}
	sort_sprite(zip);
	x = -1;
	while (++x < zip->count_sprite)
		set_sprite(zip, x);
}
