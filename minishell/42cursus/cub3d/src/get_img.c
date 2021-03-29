/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:26:08 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/03 03:38:10 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_img(t_zip *zip, int *texture, char *path, t_img *img)
{
	int		x;
	int		y;

	img->img = mlx_xpm_file_to_image(zip->mlx, path, &img->img_width, \
	&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
	&img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_height * y + x] = img->data\
			[img->img_height * y + x];
	}
	mlx_destroy_image(zip->mlx, img->img);
}

void	img_load(t_zip *zip)
{
	t_img	img;
	int		i;
	int		j;

	if (!(zip->texture = (int **)malloc(sizeof(int *) * 5)))
		cub3d_error("img malloc error");
	i = -1;
	while (i++ < 5)
		if (!(zip->texture[i] = (int *)malloc(sizeof(int) * \
		(text_height * text_width))))
			cub3d_error("img malloc error");
	i = -1;
	while (i++ < 5 && (j = -1))
		while (j++ < text_width * text_height)
			zip->texture[i][j] = 0;
	zip->buf = (int **)malloc(sizeof(int *) * (zip->height));
	i = -1;
	while (++i < zip->height)
		zip->buf[i] = (int *)malloc(sizeof(int) * (zip->width));
	get_img(zip, zip->texture[0], zip->no_texture, &img);
	get_img(zip, zip->texture[1], zip->so_texture, &img);
	get_img(zip, zip->texture[2], zip->ea_texture, &img);
	get_img(zip, zip->texture[3], zip->we_texture, &img);
	get_img(zip, zip->texture[4], zip->s_texture, &img);
}
