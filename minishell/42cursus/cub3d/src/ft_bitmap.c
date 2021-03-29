/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:44:26 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/09 19:15:53 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		push_data(unsigned char *bitmapheader, int filesize)
{
	bitmapheader[0] = (unsigned char)filesize;
	bitmapheader[1] = (unsigned char)(filesize >> 8);
	bitmapheader[2] = (unsigned char)(filesize >> 16);
	bitmapheader[3] = (unsigned char)(filesize >> 24);
}

static void		bitmap_header(int fd, int filesize, t_zip *zip)
{
	int				i;
	unsigned char	bitmapheader[54];

	i = 0;
	while (i < 54)
		bitmapheader[i++] = (unsigned char)0;
	bitmapheader[0] = (unsigned char)('B');
	bitmapheader[1] = (unsigned char)('M');
	push_data(bitmapheader + 2, filesize);
	bitmapheader[10] = (unsigned char)54;
	bitmapheader[14] = (unsigned char)40;
	push_data(bitmapheader + 18, zip->width);
	push_data(bitmapheader + 22, zip->height);
	bitmapheader[26] = (unsigned char)1;
	bitmapheader[28] = (unsigned char)24;
	write(fd, bitmapheader, 54);
}

static void		bitmap_data(int fd, t_zip *zip, int pad)
{
	int				y;
	int				x;

	y = zip->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < zip->width)
		{
			write(fd, &zip->buf[y][x], 3);
			x++;
		}
		if (pad > 0)
			write(fd, 0, pad);
		y--;
	}
}

void			get_bitmap_data(t_zip *zip)
{
	int				filesize;
	int				fd;
	int				pad;

	if ((fd = open("screenshot.bmp", \
		O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 00777)) < 0)
		return ;
	pad = (4 - (zip->width * 3) % 4) % 4;
	filesize = 54 + (3 * zip->width + pad) * zip->height;
	bitmap_header(fd, filesize, zip);
	bitmap_data(fd, zip, pad);
	exit(0);
}
