/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ukwon <Ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:24:28 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/28 14:21:21 by Ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		side_move_and_exit(t_zip *zip, double temp, double planetemp)
{
	if (zip->key_a)
	{
		if (zip->map[(int)(zip->player_x - zip->plane_x * \
		zip->move_speed * 2)][(int)(zip->player_y)] == '0')
			zip->player_x -= zip->plane_x * zip->move_speed * 2;
		if (zip->map[(int)(zip->player_x)][(int)(zip->player_y \
		- zip->plane_y * zip->move_speed * 2)] == '0')
			zip->player_y -= zip->plane_y * zip->move_speed * 2;
	}
	if (zip->key_d)
	{
		if (zip->map[(int)(zip->player_x + zip->plane_x * \
		zip->move_speed * 2)][(int)(zip->player_y)] == '0')
			zip->player_x += zip->plane_x * zip->move_speed * 2;
		if (zip->map[(int)(zip->player_x)][(int)(zip->player_y + \
		zip->plane_y * zip->move_speed * 2)] == '0')
			zip->player_y += zip->plane_y * zip->move_speed * 2;
	}
	if (zip->key_esc)
		exit(0);
}

static void		rot_right(t_zip *zip, double temp, double planetemp)
{
	temp = zip->dir_x;
	zip->dir_x = cos(-zip->rot_speed) * temp - \
	sin(-zip->rot_speed) * zip->dir_y;
	zip->dir_y = sin(-zip->rot_speed) * temp + \
	cos(-zip->rot_speed) * zip->dir_y;
	planetemp = zip->plane_x;
	zip->plane_x = cos(-zip->rot_speed) * planetemp - \
	sin(-zip->rot_speed) * zip->plane_y;
	zip->plane_y = sin(-zip->rot_speed) * planetemp + \
	cos(-zip->rot_speed) * zip->plane_y;
}

static void		rot_left(t_zip *zip, double temp, double planetemp)
{
	temp = zip->dir_x;
	zip->dir_x = cos(zip->rot_speed) * temp - \
	sin(zip->rot_speed) * zip->dir_y;
	zip->dir_y = sin(zip->rot_speed) * temp + \
	cos(zip->rot_speed) * zip->dir_y;
	planetemp = zip->plane_x;
	zip->plane_x = cos(zip->rot_speed) * planetemp - \
	sin(zip->rot_speed) * zip->plane_y;
	zip->plane_y = sin(zip->rot_speed) * planetemp + \
	cos(zip->rot_speed) * zip->plane_y;
}

void			rot_move(t_zip *zip, double temp, double planetemp)
{
	if (zip->key_q)
		rot_left(zip, temp, planetemp);
	if (zip->key_e)
		rot_right(zip, temp, planetemp);
}

int				player_move(t_zip *zip)
{
	double	temp;
	double	planetemp;

	if (zip->key_w)
	{
		if (zip->map[(int)(zip->player_x + zip->dir_x * zip->move_speed)]\
		[(int)(zip->player_y)] == '0')
			zip->player_x += zip->dir_x * zip->move_speed;
		if (zip->map[(int)(zip->player_x)][(int)(zip->player_y + zip->dir_y \
		* zip->move_speed)] == '0')
			zip->player_y += zip->dir_y * zip->move_speed;
	}
	if (zip->key_s)
	{
		if (zip->map[(int)(zip->player_x - zip->dir_x * zip->move_speed)]\
		[(int)(zip->player_y)] == '0')
			zip->player_x -= zip->dir_x * zip->move_speed;
		if (zip->map[(int)(zip->player_x)][(int)(zip->player_y - zip->dir_y \
		* zip->move_speed)] == '0')
			zip->player_y -= zip->dir_y * zip->move_speed;
	}
	rot_move(zip, temp, planetemp);
	side_move_and_exit(zip, temp, planetemp);
	return (0);
}
