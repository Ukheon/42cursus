/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:44:15 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/24 05:37:51 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void			ceil_parse(t_zip *zip);

static void			default_parsing(t_zip *zip, t_storage *head)
{
	zip->split = ft_split(zip->line, " ", zip);
	if (zip->check == 8 && *zip->split && (zip->height_size += 1))
		add_storage(head, zip->line, zip);
	else if (!(ft_strcmp(zip->split[0],"R")) && (zip->row == 3))
	{
		zip->check++;
		zip->width = ft_atoi(zip->split[1]);
		zip->height = ft_atoi(zip->split[2]);
	}
	else if (!(ft_strcmp(zip->split[0], "NO")) && \
		((zip->check += 1) && (zip->row == 2)))
		zip->no_texture = ft_strdup(zip->split[1]);
	else if (!(ft_strcmp(zip->split[0], "SO")) && \
		((zip->check += 1) && (zip->row == 2)))
		zip->so_texture = ft_strdup(zip->split[1]);
	else if (!(ft_strcmp(zip->split[0], "WE")) && \
		((zip->check += 1) && (zip->row == 2)))
		zip->we_texture = ft_strdup(zip->split[1]);
	else if (!(ft_strcmp(zip->split[0], "EA")) && \
		((zip->check += 1) && (zip->row == 2)))
		zip->ea_texture = ft_strdup(zip->split[1]);
	else if (!(ft_strcmp(zip->split[0], "S")) && \
		((zip->check += 1) && (zip->row == 2)))
		zip->s_texture = ft_strdup(zip->split[1]);
}

void	get_map(t_zip *zip, int i, int j)
{
	zip->fd = open("./cub3d", O_RDONLY);
	t_storage *head;
	head = (t_storage *)malloc(sizeof(t_storage));
	head->next = NULL;
	while ((zip->ret = get_next_line(zip->fd, &zip->line)) > 0)
	{
		zip->split = ft_split(zip->line, " ", zip);
		if (!*zip->split)
			continue;
		else if (!(ft_strcmp(zip->split[0], "C")) && (zip->check += 1))
		{
			zip->line++;
			zip->line++;
			zip->color_save = ft_split(zip->line, ", ", zip);
			zip->count = -1;
			zip->idx = 2;
			zip->c_color = 0;
			while (++zip->count < 6)
			{
				zip->num = ft_atoi(zip->color_save[zip->idx--]);
				zip->c_color += zip->num % 16 * pow(16, zip->count++);
				zip->c_color +=	zip->num / 16 * pow(16, zip->count);
			}
			free(zip->color_save);
		}
		else if (!(ft_strcmp(zip->split[0], "F")))
		{
			zip->check++;
			zip->line++;
			zip->line++;
			zip->color_save = ft_split(zip->line, ", ", zip);
			zip->count = -1;
			zip->idx = 2;
			zip->f_color = 0;
			while (++zip->count < 6)
			{
				zip->num = ft_atoi(zip->color_save[zip->idx--]);
				zip->f_color += zip->num % 16 * pow(16, zip->count++);
				zip->f_color += zip->num / 16 * pow(16, zip->count);
			}
			free(zip->color_save);
		}
	}
	zip->map = (char **)malloc(sizeof(char *) * (zip->height_size));
	i = -1;
	while (++i < zip->height_size)
	{
		zip->map[i] = (char *)malloc(sizeof(char) * (zip->width_size + 1));
		zip->map[i][zip->width_size] = '\0';
	}
	t_storage *check1 = (t_storage *)malloc(sizeof(t_storage));
	check1 = head->next;
	i = -1;
	while (++i < zip->height_size && (j = -1))
		while (++j < zip->width_size)
			zip->map[i][j] = '9';
	i = -1;
	while (++i < zip->height_size && (j = -1))
	{
		while (++j < ft_strlen(check1->data))
			if (check1->data[j] == '1' || check1->data[j] == '0' || check1->data[j] == 'N'\
			|| check1->data[j] == 'E' || check1->data[j] == 'W' || check1->data[j] == 'S'\
			 || check1->data[j] == ' ' || check1->data[j] == '2')
				zip->map[i][j] = check1->data[j];
		check1 = check1->next;
	}
	free(check1);
	free(head);
	// printf("%d %d\n",zip->width_size, zip->height_size);
}
