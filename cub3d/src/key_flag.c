/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:18:49 by Ukwon             #+#    #+#             */
/*   Updated: 2021/03/03 03:53:35 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int				key_release(int key, t_zip *zip)
{
	if (key >= 300)
		return (-1);
	if (key == W)
		zip->key_w = 0;
	else if (key == S)
		zip->key_s = 0;
	if (key == A)
		zip->key_a = 0;
	if (key == D)
		zip->key_d = 0;
	if (key == Q)
		zip->key_q = 0;
	if (key == E)
		zip->key_e = 0;
	if (key == 48)
		zip->key_m = 0;
	if (key == ESC)
		zip->key_esc = 0;
	return (0);
}

int				key_press(int key, t_zip *zip)
{
	if (key >= 300)
		return (-1);
	if (key == W)
		zip->key_w = 1;
	if (key == S)
		zip->key_s = 1;
	if (key == A)
		zip->key_a = 1;
	if (key == D)
		zip->key_d = 1;
	if (key == Q)
		zip->key_q = 1;
	if (key == E)
		zip->key_e = 1;
	if (key == 48)
		zip->key_m = 1;
	if (key == ESC)
		zip->key_esc = 1;
	return (0);
}

int				key_exit(void)
{
	exit(0);
	return (0);
}
