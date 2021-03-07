/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ukwon <Ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:44:15 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/08 00:27:51 by Ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


// void freeList(list_h* L) {
//     list* c;
//     while (L->head != NULL) {
//         c = L->head;
//         L->head = L->head->link;
//         free(c);
//         c = NULL;
//     }
// }

static void				fill_map(t_zip *zip, t_storage *head, int i, int j)
{
	t_storage	*check1;

	check1 = head->next;
	i = -1;
	while (++i < zip->height_size && (j = -1))
		while (++j < zip->width_size)
			zip->map[i][j] = ' ';
	i = -1;
	while (++i < zip->height_size && (j = -1))
	{
		while (++j < (int)(ft_strlen(check1->data)))
			if (check1->data[j] == '1' || check1->data[j] == '0' || \
			check1->data[j] == 'N' || check1->data[j] == 'E' || \
			check1->data[j] == 'W' || check1->data[j] == 'S' || \
			check1->data[j] == ' ' || check1->data[j] == '2')
				zip->map[i][j] = check1->data[j];
		check1 = check1->next;
	}
	while (head)
	{
		check1 = head->next;
		free(head->data);
		free(head);
		head = check1;
	}
}

static void				floor_parse(t_zip *zip)
{
	int			i;

	zip->check++;
	zip->color_save = ft_split(zip->line + 2, ",", zip);
	while (zip->color_save[zip->row])
		zip->row++;
	if (zip->row != 3)
		cub3d_error("floor_error");
	zip->count = -1;
	zip->idx = 2;
	zip->f_color = 0;
	while (++zip->count < 6)
	{
		zip->num = ft_atoi(zip->color_save[zip->idx--]);
		if (zip->num >= 256 || zip->num < 0)
			cub3d_error("rgb color error! ! !");
		zip->f_color += zip->num % 16 * pow(16, zip->count++);
		zip->f_color += zip->num / 16 * pow(16, zip->count);
	}
	i = 0;
	while (zip->color_save[i])
		free(zip->color_save[i++]);
	free(zip->color_save);
}

static void				ceil_parse(t_zip *zip)
{
	int			i;

	zip->check++;
	zip->color_save = ft_split(zip->line + 2, ",", zip);
	zip->row = 0;
	while (zip->color_save[zip->row])
		zip->row++;
	if (zip->row != 3)
		cub3d_error("ceil_error");
	zip->count = -1;
	zip->idx = 2;
	zip->c_color = 0;
	while (++zip->count < 6)
	{
		zip->num = ft_atoi(zip->color_save[zip->idx--]);
		if (zip->num >= 256 || zip->num < 0)
			cub3d_error("rgb color error! ! !");
		zip->c_color += zip->num % 16 * pow(16, zip->count++);
		zip->c_color += zip->num / 16 * pow(16, zip->count);
	}
	i = 0;
	while (zip->color_save[i])
		free(zip->color_save[i++]);
	free(zip->color_save);
}

static void				default_parsing(t_zip *zip, t_storage *head)
{
	if (zip->check == 8 && *zip->split && (zip->height_size += 1))
		add_storage(head, ft_strdup(zip->line), zip);
	else if (!(ft_strcmp(zip->split[0], "R")) && (zip->row == 3))
	{
		zip->check++;
		check_size(zip);
	}
	else if (!(ft_strcmp(zip->split[0], "NO")) && \
		((zip->check += 1) && (zip->row == 2)))
		no_texture(zip);
	else if (!(ft_strcmp(zip->split[0], "SO")) && \
		((zip->check += 1) && (zip->row == 2)))
		so_texture(zip);
	else if (!(ft_strcmp(zip->split[0], "WE")) && \
		((zip->check += 1) && (zip->row == 2)))
		we_texture(zip);
	else if (!(ft_strcmp(zip->split[0], "EA")) && \
		((zip->check += 1) && (zip->row == 2)))
		ea_texture(zip);
	else if (!(ft_strcmp(zip->split[0], "S")) && \
		((zip->check += 1) && (zip->row == 2)))
		s_texture(zip);
}

void					get_map(t_zip *zip, int i, char *str, t_storage *head)
{
	if ((zip->fd = open(str, O_RDONLY)) < 0)
		cub3d_error("can not open. . .");
	head = (t_storage *)malloc(sizeof(t_storage));
	head->next = NULL;
	head->data = NULL;
	while ((zip->ret = get_next_line(zip->fd, &zip->line)) > 0)
	{
		zip->split = ft_split(zip->line, " ", zip);
		if (parsing_error(zip))
		{
			split_free(zip);
			continue ;
		}
		default_parsing(zip, head);
		if (!(ft_strcmp(zip->split[0], "C")))
			ceil_parse(zip);
		else if (!(ft_strcmp(zip->split[0], "F")))
			floor_parse(zip);
		split_free(zip);
	}
	free(zip->line);
	zip->map = (char **)malloc(sizeof(char *) * (zip->height_size));
	i = -1;
	while (++i < zip->height_size)
		zip->map[i] = (char *)malloc(sizeof(char) * (zip->width_size + 1));
	fill_map(zip, head, -1, -1);
}
