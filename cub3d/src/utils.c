/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:28:56 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/04 18:45:49 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		cub3d_error(char *error)
{
	printf("%s\n", error);
	exit(0);
}

void		zip_set(t_zip *zip)
{
	zip->rot_speed = 0.03f;
	zip->move_speed = 0.05f;
	zip->count_sprite = 0;
}

void		check_size(t_zip *zip)
{
	zip->width = ft_atoi(zip->split[1]);
	zip->height = ft_atoi(zip->split[2]);
	mlx_get_screen_size(zip->mlx, &zip->w, &zip->h);
	if (zip->width >= zip->w)
		zip->width = zip->w;
	if (zip->height >= zip->h)
		zip->height = zip->h;
	if (zip->width <= 0 || zip->height <= 0)
		cub3d_error("width / height size error!!");
}

int			parsing_error(t_zip *zip)
{
	if (*zip->split)
		return (0);
	if (!(*zip->split) && zip->check == 8 && zip->height_size > 0)
		cub3d_error("empty line in map . . . . ? ? ? ? ? ! ! !");
	return (1);
}

void		add_storage(t_storage *target, char *str, t_zip *zip)
{
	t_storage *new;

	new = (t_storage *)malloc(sizeof(t_storage));
	while (target->next)
		target = target->next;
	if (zip->width_size < (int)(ft_strlen(str)))
		zip->width_size = (int)(ft_strlen(str));
	new->next = target->next;
	new->data = str;
	target->next = new;
}
