/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/21 17:26:56 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			g_check;

void		sort_sprite(t_zip *zip)
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

void	zip_set(t_zip *zip)
{
	for(int i = 0; i < map_w; i++)
	{
		for (int j = 0; j < map_h; j++)
		{
			if (map[i][j] == 5)
			{
				zip->player_x = i;
				zip->player_y = j;
				map[i][j] = 0;
			}
		}
	}
	zip->dir_x = -1.0f;
	zip->dir_y = 0.0f;
	zip->plane_x = 0.0f;
	zip->plane_y = 0.66f;
	zip->rot_speed = 0.05f;
	zip->move_speed = 0.2f;
	zip->count_sprite = 0;
}

void	draw(t_zip *zip)
{
	int		x;
	int		y;

	y = 0;
	while (y < zip->height)
	{
		x = 0;
		while (x < zip->width)
		{
			zip->img.data[y * zip->width + x] = zip->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(zip->mlx, zip->win, zip->img.img, 0, 0);
}

void	calc(t_zip *zip)
{
	int		x;
	int		y;
	unsigned int	co;

	y = 0;
	while (y < zip->height)
	{
		x = 0;
		while (x < zip->width)
		{
			if (y < zip->height / 2)
				zip->buf[y][x] = zip->c_color;
			else
				zip->buf[y][x] = zip->f_color;
			x++;
		}
		y++;
	}
	x = -1;
	while (++x < zip->width)
	{
		zip->camera = 2 * x / (double)zip->width - 1;
		zip->ray_dir_x = zip->dir_x + zip->plane_x * zip->camera;
		zip->ray_dir_y = zip->dir_y + zip->plane_y * zip->camera;
		zip->map_x = (int)zip->player_x;
		zip->map_y = (int)zip->player_y;
		zip->delta_x = fabs(1 / zip->ray_dir_x);
		zip->delta_y = fabs(1 / zip->ray_dir_y);
		if (zip->ray_dir_x < 0)
		{
			zip->step_x = -1;
			zip->side_dist_x = (zip->player_x - zip->map_x) * zip->delta_x;
		}
		else
		{
			zip->step_x = 1;
			zip->side_dist_x = (zip->map_x + 1.0 - zip->player_x) * zip->delta_x;
		}
		if (zip->ray_dir_y < 0)
		{
			zip->step_y = -1;
			zip->side_dist_y = (zip->player_y - zip->map_y) * zip->delta_y;
		}
		else
		{
			zip->step_y = 1;
			zip->side_dist_y = (zip->map_y + 1.0 - zip->player_y) * zip->delta_y;
		}
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
			if (map[zip->map_x][zip->map_y] == 1)
				zip->hit = 1;
		}

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

void	get_img(t_zip *zip, int *texture, char *path, t_img *img)
{
	int		x;
	int		y;

	img->img = mlx_xpm_file_to_image(zip->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_height * y + x] = img->data[img->img_height * y + x];
	}
	mlx_destroy_image(zip->mlx, img->img);
}

void	img_load(t_zip *zip)
{
	t_img	img;
	// printf("why?\n");
	// printf("come img_load\n");
	// get_img(zip, zip->texture[0], "textures/color1.xpm", &img);
	// get_img(zip, zip->texture[1], "textures/color2.xpm", &img);
	// get_img(zip, zip->texture[2], "textures/color3.xpm", &img);
	// get_img(zip, zip->texture[3], "textures/color4.xpm", &img);
	// get_img(zip, zip->texture[4], "textures/pillar.xpm", &img);
	// printf("%s\n%s\n%s\n%s\n", zip->no_texture, zip->so_texture, zip->ea_texture,zip->we_texture);
// 	printf("%s\n",zip->no_texture);
// 	printf("why?\n");printf("why?\n");printf("why?\n");
// 	printf("why?\n");
	get_img(zip, zip->texture[0], zip->no_texture, &img);
	get_img(zip, zip->texture[1], zip->so_texture, &img);
	get_img(zip, zip->texture[2], zip->ea_texture, &img);
	get_img(zip, zip->texture[3], zip->we_texture, &img);
	get_img(zip, zip->texture[4], zip->s_texture, &img);
}

int		main_loop(t_zip *zip)
{
	calc(zip);
	draw(zip);
	return (0);
}

int		player_move(int	keycode, t_zip *zip)
{
	double	temp;
	double	planetemp;

	if (keycode == W)
	{
		if (!map[(int)(zip->player_x + zip->dir_x * zip->move_speed)][(int)(zip->player_y)])
			zip->player_x += zip->dir_x * zip->move_speed;
		if (!map[(int)(zip->player_x)][(int)(zip->player_y + zip->dir_y * zip->move_speed)])
			zip->player_y += zip->dir_y * zip->move_speed;
	}
	if (keycode == S)
	{
		if (!map[(int)(zip->player_x - zip->dir_x * zip->move_speed)][(int)(zip->player_y)])
			zip->player_x -= zip->dir_x * zip->move_speed;
		if (!map[(int)(zip->player_x)][(int)(zip->player_y - zip->dir_y * zip->move_speed)])
			zip->player_y -= zip->dir_y * zip->move_speed;
	}
	if (keycode == Q)
	{
		temp = zip->dir_x;
		zip->dir_x = cos(zip->rot_speed) * temp - sin(zip->rot_speed) * zip->dir_y;
		zip->dir_y = sin(zip->rot_speed) * temp + cos(zip->rot_speed) * zip->dir_y;
		planetemp = zip->plane_x;
		zip->plane_x = cos(zip->rot_speed) * planetemp - sin(zip->rot_speed) * zip->plane_y;
		zip->plane_y = sin(zip->rot_speed) * planetemp + cos(zip->rot_speed) * zip->plane_y;
	}
	if (keycode == E)
	{
		temp = zip->dir_x;
		zip->dir_x = cos(-zip->rot_speed) * temp - sin(-zip->rot_speed) * zip->dir_y;
		zip->dir_y = sin(-zip->rot_speed) * temp + cos(-zip->rot_speed) * zip->dir_y;
		planetemp = zip->plane_x;
		zip->plane_x = cos(-zip->rot_speed) * planetemp - sin(-zip->rot_speed) * zip->plane_y;
		zip->plane_y = sin(-zip->rot_speed) * planetemp + cos(-zip->rot_speed) * zip->plane_y;
	}
	if (keycode == A)
	{
		if (!map[(int)(zip->player_x - zip->plane_x * zip->move_speed * 2)][(int)(zip->player_y)])
		{
			zip->player_x -= zip->plane_x * zip->move_speed * 2;
		}
		if (!map[(int)(zip->player_x)][(int)(zip->player_y - zip->plane_y * zip->move_speed * 2)])
			zip->player_y -= zip->plane_y * zip->move_speed * 2;
	}
	if (keycode == D)
	{
		if (!map[(int)(zip->player_x + zip->plane_x * zip->move_speed * 2)][(int)(zip->player_y)])
			zip->player_x += zip->plane_x * zip->move_speed * 2;
		if (!map[(int)(zip->player_x)][(int)(zip->player_y + zip->plane_y * zip->move_speed * 2)])
			zip->player_y += zip->plane_y * zip->move_speed * 2;
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}

void		add_storage(t_storage *target, char *str, t_zip *zip)
{
	t_storage *new;
	new = (t_storage *)malloc(sizeof(t_storage));

	new->next = target->next;
	new->data = str;
	target->next = new;
}

void	get_map(t_zip *zip)
{
	char	*line;
	char	**save;
	int		i;


	zip->ret = 0;
	i = 0;
	line = 0;
	zip->check = 0;
	zip->fd = open("./map", O_RDONLY);
	zip->width_size = 0;
	zip->height_size = 0;
	t_storage *head;
	head = (t_storage *)malloc(sizeof(t_storage));
	while ((zip->ret = get_next_line(zip->fd, &line)) > 0)
	{
		save = ft_split(line, ' ');
		if (zip->check == 1)
		{
			zip->height_size++;
			if (zip->width_size < ft_strlen(line))
				zip->width_size = ft_strlen(line);
			add_storage(head, line, zip);
		}
		if (!*save)
		{
			zip->check = 1;
			continue;
		}
		else if (!(ft_strcmp(save[0],"R")))
		{
			zip->width = ft_atoi(save[1]);
			zip->height = ft_atoi(save[2]);
		}
		else if (!(ft_strcmp(save[0], "NO")))
			zip->no_texture = ft_strdup(save[1]);
		else if (!(ft_strcmp(save[0], "SO")))
			zip->so_texture = ft_strdup(save[1]);
		else if (!(ft_strcmp(save[0], "WE")))
			zip->we_texture = ft_strdup(save[1]);
		else if (!(ft_strcmp(save[0], "EA")))
			zip->ea_texture = ft_strdup(save[1]);
		else if (!(ft_strcmp(save[0], "S")))
			zip->s_texture = ft_strdup(save[1]);
		else if (!(ft_strcmp(save[0], "C")))
		{
			zip->color_save = ft_split(save[1], ',');
			zip->count = -1;
			zip->idx = 2;
			zip->c_color = 0;
			while (++zip->count < 6)
			{
				zip->num = ft_atoi(zip->color_save[zip->idx--]);
				zip->c_color += zip->num % 16 * pow(16, zip->count++);
				zip->c_color +=	zip->num / 16 * pow(16, zip->count);
			}
			free(zip->color_save);
		}
		else if (!(ft_strcmp(save[0], "F")))
		{
			zip->color_save = ft_split(save[1], ',');
			zip->count = -1;
			zip->idx = 2;
			zip->f_color = 0;
			while (++zip->count < 6)
			{
				zip->num = ft_atoi(zip->color_save[zip->idx--]);
				zip->f_color += zip->num % 16 * pow(16, zip->count++);
				zip->f_color += zip->num / 16 * pow(16, zip->count);
			}
			free(zip->color_save);
		}
	}
}

int		main(int argc, char *argv[])
{
	t_zip	zip;
	int		i;
	int		j;
	int		idx;

	// printf("why?\n");
	zip.mlx = mlx_init();
	zip.width = 640;
	zip.height = 640;
	get_map(&zip);
	zip_set(&zip);
	if (!(zip.texture = (int **)malloc(sizeof(int *) * 5)))
		return (-1);
	i = -1;
	while (i++ < 5)
	{
		if (!(zip.texture[i] = (int *)malloc(sizeof(int) * (text_height * text_width))))
			return (-1);
	}
	i = -1;
	while (i++ < 5)
	{
		j = -1;
		while (j++ < text_width * text_height)
			zip.texture[i][j] = 0;
	}
	i = -1;
	while (i ++ < map_w)
	{
		j = -1;
		while (j++ < map_h)
		{
			if (map[i][j] == 2)
				zip.count_sprite++;
		}
	}
	i = -1;
	idx = 0;

	zip.sprite = (t_sprite *)malloc(sizeof(t_sprite) * zip.count_sprite);

	while (i++ < map_w)
	{
		j = -1;
		while (j++ < map_h)
		{
			if (map[i][j] == 2)
			{
				map[i][j] = 0;
				zip.sprite[idx].x = i;
				zip.sprite[idx++].y = j;
			}
		}
	}
	zip.buf = (int **)malloc(sizeof(int *) * zip.height);
	i = -1;
	while (++i < zip.height)
		zip.buf[i] = (int *)malloc(sizeof(int) * zip.width);
	img_load(&zip);
	zip.win = mlx_new_window(zip.mlx, zip.width, zip.height, "Cub3D");

	zip.img.img = mlx_new_image(zip.mlx, zip.width, zip.height);
	zip.img.data = (int *)mlx_get_data_addr(zip.img.img, &zip.img.bpp, &zip.img.size_l, &zip.img.endian);

	mlx_loop_hook(zip.mlx, &main_loop, &zip);
	mlx_hook(zip.win, 2, 0, &player_move, &zip);
	mlx_loop(zip.mlx);
}
