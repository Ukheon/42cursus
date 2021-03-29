/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/10 13:09:10 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	zip_set(t_zip *zip)
{
	zip->rot_speed = 0.03f;
	zip->move_speed = 0.05f;
	zip->count_sprite = 0;
	zip->c_check = 0;
	zip->r_check = 0;
	zip->f_check = 0;
	zip->no_check = 0;
	zip->so_check = 0;
	zip->ea_check = 0;
	zip->we_check = 0;
	zip->s_check = 0;
}

void	draw(t_zip *zip, int x, int y)
{
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
	if (zip->key_m)
		draw_map(zip);
}

int		main_loop(t_zip *zip)
{
	calc(zip, -1, -1);
	draw(zip, 0, 0);
	player_move(zip);
	return (0);
}

void	init_game(t_zip *zip, char *str)
{
	zip_set(zip);
	get_map(zip, 0, str, 0);
	map_check(zip);
	check_player_vec(zip);
	zip->mlx = mlx_init();
	img_load(zip);
	zip->win = mlx_new_window(zip->mlx, zip->width, zip->height, "Cub3D");
	zip->img.img = mlx_new_image(zip->mlx, zip->width, zip->height);
	zip->img.data = (int *)mlx_get_data_addr(zip->img.img, &zip->img.bpp, \
	&zip->img.size_l, &zip->img.endian);
	mlx_loop_hook(zip->mlx, &main_loop, zip);
	mlx_hook(zip->win, 2, 0, &key_press, zip);
	mlx_hook(zip->win, 3, 0, &key_release, zip);
	mlx_hook(zip->win, 17, 0, &key_exit, zip);
	mlx_loop(zip->mlx);
}

int		main(int argc, char *argv[])
{
	t_zip	zip;

	cub_file_check(argc, argv[1]);
	if (argc == 2)
		init_game(&zip, argv[1]);
	else if (argc == 3 && !(ft_strcmp(argv[2], "--save")))
	{
		zip_set(&zip);
		get_map(&zip, 0, argv[1], 0);
		map_check(&zip);
		check_player_vec(&zip);
		zip.mlx = mlx_init();
		img_load(&zip);
		zip.img.img = mlx_new_image(zip.mlx, zip.width, zip.height);
		zip.img.data = (int *)mlx_get_data_addr(zip.img.img, &zip.img.bpp, \
		&zip.img.size_l, &zip.img.endian);
		calc(&zip, -1, -1);
		get_bitmap_data(&zip);
	}
	else
		cub3d_error("wrong parameter");
	return (0);
}