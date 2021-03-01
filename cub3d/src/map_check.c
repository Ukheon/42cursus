/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:43:46 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/01 22:38:41 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		map_row_test(int i, int j, t_zip *zip)
{
	zip->temp_i = i;
	zip->temp_j = j;
	while (i < zip->height_size)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub3d_error("map check error");
		i++;
	}
	if (zip->check != 1)
		cub3d_error("map check error");
	i = zip->temp_i;
	j = zip->temp_j;
	zip->check = 0;
	while (i >= 0)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub3d_error("map check error");
		i--;
	}
	if (zip->check != 1)
		cub3d_error("map check error");
}

void		map_col_test(int i, int j, t_zip *zip)
{
	zip->temp_i = i;
	zip->temp_j = j;
	while (j < zip->width_size)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub3d_error("map check error");
		j++;
	}
	if (zip->check != 1)
		cub3d_error("map check error");
	i = zip->temp_i;
	j = zip->temp_j;
	zip->check = 0;
	while (j >= 0)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub3d_error("map check error");
		j--;
	}
	if (zip->check != 1)
		cub3d_error("map check error");
}

static void	map_splite_check(t_zip *zip, int idx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < zip->height_size && (j = -1))
		while (++j < zip->width_size)
			if (zip->map[i][j] == '2')
				zip->count_sprite++;
	i = -1;
	zip->sprite = (t_sprite *)malloc(sizeof(t_sprite) * zip->count_sprite);
	while (++i < zip->height_size)
	{
		j = -1;
		while (++j < zip->width_size)
		{
			if (zip->map[i][j] == '2')
			{
				zip->sprite[idx].x = i + 0.5;
				zip->sprite[idx++].y = j + 0.5;
			}
		}
	}
}

void		map_check(t_zip *zip)
{
	int			i;
	int			j;

	map_splite_check(zip, 0);
	i = -1;
	while (++i < zip->height_size)
	{
		j = -1;
		while (++j < zip->width_size)
		{
			if (zip->map[i][j] == '0')
			{
				zip->check = 0;
				map_col_test(i, j, zip);
				zip->check = 0;
				map_row_test(i, j, zip);
			}
			if (zip->map[i][j] == 'N' || zip->map[i][j] == 'S' \
			|| zip->map[i][j] == 'E' || zip->map[i][j] == 'W')
				zip->player_check += 1;
		}
	}
	if (zip->player_check != 1)
		cub3d_error("error");
}
