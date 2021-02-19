/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/18 18:35:50 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define A 0
#define S 1
#define D 2
#define W 13
#define Q 12
#define E 14
#define ESC 53
#define map_w 24
#define map_h 24
#define text_width 64
#define text_height 64

// int		map[map_w][map_h] = {
// 		{2,2,2,2,2,2,2,2,2,2},
// 		{8,0,2,0,2,0,2,0,2,8},
// 		{8,0,0,0,0,0,0,0,0,8},
// 		{8,0,0,0,0,0,0,0,0,8},
// 		{8,0,0,0,0,0,0,0,0,8},
// 		{8,0,0,0,0,0,0,0,0,8},
// 		{8,0,0,0,0,0,0,0,0,8},
// 		{8,0,0,0,0,0,0,0,0,8},
// 		{8,0,0,0,0,0,0,0,0,8},
// 		{8,8,8,8,8,8,8,8,8,8}
// };

int	map[map_w][map_h] =
									{
										{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
										{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
									};

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		len;
	int			index;
}				t_sprite;

typedef struct	s_zip
{
	int			num;
	int			res;
	int			count;
	int			idx;
	char		**color_save;
	int			c_color;
	int			f_color;
	int			map_width;
	int			map_height;
	int			width;
	int			height;
	double		save_wall_len[4096];
	void		*mlx;
	void		*win;
	t_img		img;
	double		dir_x;
	double		dir_y;
	double		player_x;
	double		player_y;
	double		ray_x;
	double		ray_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;

	int			**buf;
	int			**texture;

	double		camera;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_x;
	double		delta_y;
	double		raylen;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;

	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall;
	int			text_num;
	int			text_x;
	int			text_y;
	double		text_step;
	double		text_pos;

	int			count_sprite;
	int			*order;
	t_sprite	*sprite;
	double		relative_x;
	double		relative_y;
	double		transform_x;
	double		transform_y;
	int			sprite_screen;
	int			sprite_height;
	int			sprite_width;
	int			sprite_start_x;
	int			sprite_start_y;
	int			sprite_end_x;
	int			sprite_end_y;
	int			color;
	double		sub;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*s_texture;
}				t_zip;

void		get_map(t_zip *zip);
void		sort_sprite(t_zip *zip);
void		zip_set(t_zip *zip);
void		draw(t_zip *zip);
void		calc(t_zip *zip);
void		get_img(t_zip *zip, int *texture, char *path, t_img *img);
void		img_load(t_zip *zip);
int			main_loop(t_zip *zip);
int			player_move(int	keycode, t_zip *zip);
