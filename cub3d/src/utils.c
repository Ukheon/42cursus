/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:28:56 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/26 20:32:53 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		cub3d_error(void)
{
	printf("Are you kidding me? I want the right file!");
	exit(0);
}

void		zip_set(t_zip *zip)
{
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
