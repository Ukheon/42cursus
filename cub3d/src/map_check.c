#include "../include/cub3d.h"

void	map_row_test(int i, int j, t_zip *zip)
{
	zip->temp_i = i;
	zip->temp_j = j;
	zip->check = 0;


	while (i < zip->height_size)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub_file_error(i, j);
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
			cub_file_error(i , j);
		i--;
	}
	if (zip->check != 1)
		cub_file_error(i , j);
}

void	map_col_test(int i, int j, t_zip *zip)
{
	zip->check = 0;
	zip->temp_i = i;
	zip->temp_j = j;

	while (j < zip->width_size)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub_file_error(i, j);
		j++;
	}
	if (zip->check != 1)
		cub_file_error(i,j);

	i = zip->temp_i;
	j = zip->temp_j;
	zip->check = 0;
	while (j >= 0)
	{
		if (zip->map[i][j] == '1')
			zip->check = 1;
		if (zip->check == 0 && zip->map[i][j] == ' ')
			cub_file_error(i,j);

		j--;
	}
	if (zip->check != 1)
	{

		cub_file_error(i,j);
	}
}

void	map_check(t_zip *zip)
{
	int			i;
	int			j;
	int			test;

	test = 0;
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
			if (zip->map[i][j] == 'N')
				zip->player_check = 1;
		}
	}
	if (!zip->player_check)
		cub_file_error(i, j);
}
