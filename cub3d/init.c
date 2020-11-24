#include "mlx.h"
#include <stdlib.h>

int		map[11][11] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};

typedef struct	s_pix
{
	void		*ptr;
	void		*win;
	int			x;
	int			y;
	int			**map;
	void		*img_ptr;
	int			*img;
}				t_pix;

int			player_show(t_pix *pix)
{
	int i;
	int j;

	i = 0;
	while (i <= 10)
	{
		j = 0;
		while (j++ <= 10)
			mlx_pixel_put(pix->ptr, pix->win, pix->x + i, pix->y + j, 0xff0000);
		i++;
	}
	j = 0;
	i = 5;
	while (j++ <= 100)
	{
		mlx_pixel_put(pix->ptr, pix->win, pix->x + i, pix->y - j, 0xff0000);
	}
	return (0);
}

int			player_move(int keycode, t_pix *pix)
{
	int		i;
	int		j;

	i = 0;
	if (keycode == 1)
		pix->y += 5;
	else if (keycode == 13)
		pix->y -= 5;
	else if (keycode == 2)
		pix->x += 5;
	else if (keycode == 0)
		pix->x -= 5;
	else if (keycode == 53)
		exit(0);
	return (0);
}

int			draw_map(t_pix *pix)
{
	int count_h;
	int IMG_HEIGHT = 1000;
	int	IMG_WIDTH = 1000;
	int count_w = -1;
	int bpp;
	int size;
	int endian;
	pix->img = (int *)mlx_get_data_addr(pix->img_ptr, &bpp,&size,&endian);
	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_w % 2)
				pix->img[count_h * IMG_WIDTH + count_w] = 0xffffff;
			else
				pix->img[count_h * IMG_WIDTH + count_w] = 0xffffff;
		}
	}
	return (1);
}

void		show_wall(t_pix *pix)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (map[i][j] == 1)
				mlx_put_image_to_window(pix->ptr, pix->win, pix->img_ptr, j * 100, i * 100);
			j++;
		}
		i++;
	}
}

int			put_pix(t_pix *pix)
{
	int		i;
	int		j;
	int		width;
	int		height;

	height = 1000; // admin
	width = 1000;
	mlx_clear_window(pix->ptr, pix->win);

	show_wall(pix);
	i = 1;
	while (i <= 10)
	{
		j = 0;
		while (j <= width)
		{
			mlx_pixel_put(pix->ptr, pix->win, i * 100, j, 0x00ff00);
			j++;
		}
		i++;
	}
	i = 1;
	while (i <= 10)
	{
		j = 0;
		while (j <= width)
		{
			mlx_pixel_put(pix->ptr, pix->win, j, i * 100, 0x00ff00);
			j++;
		}
		i++;
	}
	player_show(pix);
	return (0);
}

int			main(void)
{
	t_pix	pix;
	t_pix	pix2;

	pix.x = 220;
	pix.y = 220;
	pix.ptr = mlx_init();
	pix.win = mlx_new_window(pix.ptr, 1000, 1000, "ukheon");
	pix.img_ptr = mlx_new_image(pix.ptr, 100, 100);
	draw_map(&pix);
	mlx_loop_hook(pix.ptr, &put_pix, &pix);
	mlx_hook(pix.win, 4, 0, &player_move, &pix);
	mlx_loop(pix.ptr);
}
