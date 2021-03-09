/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:47:44 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/09 14:44:41 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		check_n(t_zip *zip, int i, int j)
{
	zip->player_x = i + 0.5;
	zip->player_y = j + 0.5;
	zip->dir_x = -1.0f;
	zip->dir_y = 0.0f;
	zip->plane_x = 0.0f;
	zip->plane_y = 0.5f;
	zip->map[i][j] = '0';
}

static void		check_w(t_zip *zip, int i, int j)
{
	zip->player_x = i + 0.5;
	zip->player_y = j + 0.5;
	zip->dir_x = 0.0f;
	zip->dir_y = -1.0f;
	zip->plane_x = -0.5f;
	zip->plane_y = 0.0f;
	zip->map[i][j] = '0';
}

static void		check_e(t_zip *zip, int i, int j)
{
	zip->player_x = i + 0.5;
	zip->player_y = j + 0.5;
	zip->dir_x = 0.0f;
	zip->dir_y = 1.0f;
	zip->plane_x = 0.66f;
	zip->plane_y = 0.0f;
	zip->map[i][j] = '0';
}

static void		check_s(t_zip *zip, int i, int j)
{
	zip->player_x = i + 0.5;
	zip->player_y = j + 0.5;
	zip->dir_x = 1.0f;
	zip->dir_y = 0.0f;
	zip->plane_x = 0.0f;
	zip->plane_y = -0.5f;
	zip->map[i][j] = '0';
}

void			check_player_vec(t_zip *zip)
{
	int			i;
	int			j;

	i = 0;
	while (i < zip->height_size)
	{
		j = 0;
		while (j < zip->width_size)
		{
			if (zip->map[i][j] == 'N')
				check_n(zip, i, j);
			if (zip->map[i][j] == 'W')
				check_w(zip, i, j);
			if (zip->map[i][j] == 'E')
				check_e(zip, i, j);
			if (zip->map[i][j] == 'S')
				check_s(zip, i, j);
			j++;
		}
		i++;
	}
}
