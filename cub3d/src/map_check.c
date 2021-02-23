/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:43:46 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/24 05:27:49 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	map_row_test(int i, int j, t_zip *zip)
{
	zip->temp_i = i;
	zip->temp_j = j;
	while (i < zip->height_size)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub_file_error();
		i++;
	}
	if (zip->check != 1)
		cub_file_error(i, j);
	i = zip->temp_i;
	j = zip->temp_j;
	zip->check = 0;
	while (i >= 0)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub_file_error();
		i--;
	}
	if (zip->check != 1)
		cub_file_error();
}

void	map_col_test(int i, int j, t_zip *zip)
{
	zip->temp_i = i;
	zip->temp_j = j;
	while (j < zip->width_size)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub_file_error();
		j++;
	}
	if (zip->check != 1)
		cub_file_error();
	i = zip->temp_i;
	j = zip->temp_j;
	zip->check = 0;
	while (j >= 0)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub_file_error();
		j--;
	}
	if (zip->check != 1)
		cub_file_error();
}

void	map_check(t_zip *zip)
{
	int			i;
	int			j;

	zip->check = 0;
	i = -1;
	while (++i < zip->height_size)
	{
		j = -1;
		while (++j < zip->width_size)
		{
			if (zip->map[i][j] == '0')
			{
				map_row_test(i, j, zip);
				map_col_test(i, j, zip);
			}
			if (zip->map[i][j] == 'N' || zip->map[i][j] == 'S' \
			|| zip->map[i][j] == 'E' || zip->map[i][j] == 'W')
				zip->player_check += 1;
		}
	}
	if (zip->player_check != 1)
		cub_file_error();
}
