/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:30:45 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/09 16:20:57 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	no_texture(t_zip *zip)
{
	int		fd;

	zip->no_texture = ft_strdup(zip->split[1]);
	if ((fd = open(zip->no_texture, O_RDONLY)) < 0)
		cub3d_error("texture error");
}

void	we_texture(t_zip *zip)
{
	int		fd;

	zip->we_texture = ft_strdup(zip->split[1]);
	if ((fd = open(zip->we_texture, O_RDONLY)) < 0)
		cub3d_error("texture error");
}

void	ea_texture(t_zip *zip)
{
	int		fd;

	zip->ea_texture = ft_strdup(zip->split[1]);
	if ((fd = open(zip->ea_texture, O_RDONLY)) < 0)
		cub3d_error("texture error");
}

void	so_texture(t_zip *zip)
{
	int		fd;

	zip->so_texture = ft_strdup(zip->split[1]);
	if ((fd = open(zip->so_texture, O_RDONLY)) < 0)
		cub3d_error("texture error");
}

void	s_texture(t_zip *zip)
{
	int		fd;

	zip->s_texture = ft_strdup(zip->split[1]);
	if ((fd = open(zip->s_texture, O_RDONLY)) < 0)
		cub3d_error("texture error");
}
