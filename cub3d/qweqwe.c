/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qweqwe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/26 20:02:35 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	zip_set(t_zip *zip)
{
	zip->rot_speed = 0.05f;
	zip->move_speed = 0.2f;
	zip->count_sprite = 0;
}

void	draw(t_zip *zip, int x, int y)
{
	y = 0;
	while (y < zip->height)
	{
		x = 0;
		while (x < zip->width)
		{
			zip->img.data[y * zip->height + x] = zip->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(zip->mlx, zip->win, zip->img.img, 0, 0);
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
	int		i;
	int		j;

	if (!(zip->texture = (int **)malloc(sizeof(int *) * 5)))
		cub3d_error();
	i = -1;
	while (i++ < 5)
		if (!(zip->texture[i] = (int *)malloc(sizeof(int) * (text_height * text_width))))
			cub3d_error();
	i = -1;
	while (i++ < 5 && (j = -1))
		while (j++ < text_width * text_height)
			zip->texture[i][j] = 0;
	zip->buf = (int **)malloc(sizeof(int *) * zip->height);
	i = -1;
	while (++i < zip->height)
		zip->buf[i] = (int *)malloc(sizeof(int) * zip->width);
	get_img(zip, zip->texture[0], zip->no_texture, &img);
	get_img(zip, zip->texture[1], zip->so_texture, &img);
	get_img(zip, zip->texture[2], zip->ea_texture, &img);
	get_img(zip, zip->texture[3], zip->we_texture, &img);
	get_img(zip, zip->texture[4], zip->s_texture, &img);
}

int		main_loop(t_zip *zip)
{
	calc(zip, -1, -1);
	draw(zip, 0, 0);
	player_move(zip);
	return (0);
}

int		player_move(int key, t_zip *zip)
{
	double	temp;
	double	planetemp;

	if (key == W)
	{
		if (zip->map[(int)(zip->player_x + zip->dir_x * zip->move_speed)][(int)(zip->player_y)] == '0')
			zip->player_x += zip->dir_x * zip->move_speed;
		if (zip->map[(int)(zip->player_x)][(int)(zip->player_y + zip->dir_y * zip->move_speed)] == '0')
			zip->player_y += zip->dir_y * zip->move_speed;
	}
	if (key == S)
	{
		if (zip->map[(int)(zip->player_x - zip->dir_x * zip->move_speed)][(int)(zip->player_y)] == '0')
			zip->player_x -= zip->dir_x * zip->move_speed;
		if (zip->map[(int)(zip->player_x)][(int)(zip->player_y - zip->dir_y * zip->move_speed)] == '0')
			zip->player_y -= zip->dir_y * zip->move_speed;
	}
	if (key == Q)
	{
		temp = zip->dir_x;
		zip->dir_x = cos(zip->rot_speed) * temp - sin(zip->rot_speed) * zip->dir_y;
		zip->dir_y = sin(zip->rot_speed) * temp + cos(zip->rot_speed) * zip->dir_y;
		planetemp = zip->plane_x;
		zip->plane_x = cos(zip->rot_speed) * planetemp - sin(zip->rot_speed) * zip->plane_y;
		zip->plane_y = sin(zip->rot_speed) * planetemp + cos(zip->rot_speed) * zip->plane_y;
	}
	if (key == E)
	{
		temp = zip->dir_x;
		zip->dir_x = cos(-zip->rot_speed) * temp - sin(-zip->rot_speed) * zip->dir_y;
		zip->dir_y = sin(-zip->rot_speed) * temp + cos(-zip->rot_speed) * zip->dir_y;
		planetemp = zip->plane_x;
		zip->plane_x = cos(-zip->rot_speed) * planetemp - sin(-zip->rot_speed) * zip->plane_y;
		zip->plane_y = sin(-zip->rot_speed) * planetemp + cos(-zip->rot_speed) * zip->plane_y;
	}
	if (key == A)
	{
		if (zip->map[(int)(zip->player_x - zip->plane_x * zip->move_speed * 2)][(int)(zip->player_y)] == '0')
			zip->player_x -= zip->plane_x * zip->move_speed * 2;
		if (zip->map[(int)(zip->player_x)][(int)(zip->player_y - zip->plane_y * zip->move_speed * 2)] == '0')
			zip->player_y -= zip->plane_y * zip->move_speed * 2;
	}
	if (key == D)
	{
		if (zip->map[(int)(zip->player_x + zip->plane_x * zip->move_speed * 2)][(int)(zip->player_y)] == '0')
			zip->player_x += zip->plane_x * zip->move_speed * 2;
		if (zip->map[(int)(zip->player_x)][(int)(zip->player_y + zip->plane_y * zip->move_speed * 2)] == '0')
			zip->player_y += zip->plane_y * zip->move_speed * 2;
	}
	if (key == ESC)
		exit(0);
	return (0);
}

void		add_storage(t_storage *target, char *str, t_zip *zip)
{
	t_storage *new;
	new = (t_storage *)malloc(sizeof(t_storage));
	while(target->next)
		target = target->next;
	if (zip->width_size < ft_strlen(str))
		zip->width_size = ft_strlen(str);
	new->next = target->next;
	new->data = str;
	target->next = new;
}

void	cub3d_error()
{
	printf("Are you kidding me? I want the right file!");
	exit(0);
}

int		key_release(int key, t_zip *zip)
{
	if (key >= 300)
		return (-1);
	if (key == W)
		zip->key_w = 0;
	if (key == S)
		zip->key_s = 0;
	if (key == A)
		zip->key_a = 0;
	if (key == D)
		zip->key_d = 0;
	if (key == Q)
		zip->key_q = 0;
	if (key == E)
		zip->key_e = 0;
	if (key == ESC)
		zip->key_esc = 0;
	return (0);
}

int		key_press(int key, t_zip *zip)
{
	if (key >= 300)
		return (-1);
	printf("%d\n",key);
	if (key == W)
		zip->key_w = 1;
	if (key == S)
		zip->key_s = 1;
	if (key == A)
		zip->key_a = 1;
	if (key == D)
		zip->key_d = 1;
	if (key == Q)
		zip->key_q = 1;
	if (key == E)
		zip->key_e = 1;
	if (key == ESC)
		zip->key_esc = 1;
	return (0);
}

int		main(int argc, char *argv[])
{
	t_zip	zip;

	if (argc == 1)
	{
		get_map(&zip, 0, 0);
		zip_set(&zip);
		map_check(&zip);
		check_player_vec(&zip);
		zip.mlx = mlx_init();
		img_load(&zip);
		zip.win = mlx_new_window(zip.mlx, zip.width, zip.height, "Cub3D");
		zip.img.img = mlx_new_image(zip.mlx, zip.width, zip.height);
		zip.img.data = (int *)mlx_get_data_addr(zip.img.img, &zip.img.bpp, \
		&zip.img.size_l, &zip.img.endian);
		mlx_loop_hook(zip.mlx, &main_loop, &zip);
		mlx_hook(zip.win, 2, 0, &player_move, &zip);
		// mlx_hook(zip.win, 3, 0, &key_release, &zip);
		mlx_loop(zip.mlx);
	}
	else
		cub3d_error();
	return (0);
}
