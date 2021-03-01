/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ukwon <Ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:28:56 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/28 17:45:19 by Ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		cub3d_error(char *error)
{
	printf("%s\n", error);
	exit(0);
}

void		check_size(t_zip *zip)
{
	zip->width = ft_atoi(zip->split[1]);
	zip->height = ft_atoi(zip->split[2]);
	if (zip->width >= 1794)
		zip->width = 1794;
	if (zip->height >= 1070)
		zip->height = 1070;
	if (zip->width <= 0 || zip->height <= 0)
		cub3d_error("width / height size error!!");
}

void		zip_set(t_zip *zip)
{
	zip->up_down = 0;
	zip->rot_speed = 0.03f;
	zip->move_speed = 0.05f;
	zip->count_sprite = 0;
}

void		add_storage(t_storage *target, char *str, t_zip *zip)
{
	t_storage *new;

	new = (t_storage *)malloc(sizeof(t_storage));
	while (target->next)
		target = target->next;
	if (zip->width_size < ft_strlen(str))
		zip->width_size = ft_strlen(str);
	new->next = target->next;
	new->data = str;
	target->next = new;
}
