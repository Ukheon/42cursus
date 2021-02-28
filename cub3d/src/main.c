/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ukwon <Ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/28 13:19:15 by Ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
}

int		main_loop(t_zip *zip)
{
	calc(zip, -1, -1);
	draw(zip, 0, 0);
	player_move(zip);
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
		mlx_hook(zip.win, 2, 0, &key_press, &zip);
		mlx_hook(zip.win, 3, 0, &key_release, &zip);
		mlx_loop(zip.mlx);
	}
	else if (argc == 2 && !(ft_strcmp(argv[1], "--save")))
	{
		get_map(&zip, 0, 0);
		zip_set(&zip);
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
		cub3d_error("error");
	return (0);
}
