#include "../include/cub3d.h"

void	get_map(t_zip *zip)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	zip->ret = 0;
	zip->line = 0;
	zip->check = 0;
	zip->fd = open("./cub3d", O_RDONLY);
	zip->width_size = 0;
	zip->height_size = 0;
	t_storage *head;
	head = (t_storage *)malloc(sizeof(t_storage));
	head->next = NULL;
	while ((zip->ret = get_next_line(zip->fd, &zip->line)) > 0)
	{
		zip->split_data = ft_split(zip->line, " ", zip);
		if (zip->check == 8 && *zip->split_data)
		{
			zip->height_size++;
			add_storage(head, zip->line, zip);
		}
		if (!*zip->split_data)
			continue;
		else if (!(ft_strcmp(zip->split_data[0],"R")) && zip->row_check == 3)
		{
			zip->check++;
			zip->width = ft_atoi(zip->split_data[1]);
			zip->height = ft_atoi(zip->split_data[2]);
		}
		else if (!(ft_strcmp(zip->split_data[0], "NO")) && zip->row_check == 2)
		{
			zip->check++;
			zip->no_texture = ft_strdup(zip->split_data[1]);
		}
		else if (!(ft_strcmp(zip->split_data[0], "SO")) && zip->row_check == 2)
		{
			zip->check++;
			zip->so_texture = ft_strdup(zip->split_data[1]);
		}
		else if (!(ft_strcmp(zip->split_data[0], "WE")) && zip->row_check == 2)
		{
			zip->check++;
			zip->we_texture = ft_strdup(zip->split_data[1]);
		}
		else if (!(ft_strcmp(zip->split_data[0], "EA")) && zip->row_check == 2)
		{
			zip->check++;
			zip->ea_texture = ft_strdup(zip->split_data[1]);
		}
		else if (!(ft_strcmp(zip->split_data[0], "S")) && zip->row_check == 2)
		{
			zip->check++;
			zip->s_texture = ft_strdup(zip->split_data[1]);
		}
		else if (!(ft_strcmp(zip->split_data[0], "C")))
		{
			zip->check++;
			zip->line++;
			zip->line++;
			zip->color_save = ft_split(zip->line, ", ", zip);
			// if (zip->row_check != 4)
			// 	break ;
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
		else if (!(ft_strcmp(zip->split_data[0], "F")))
		{
			zip->check++;
			zip->line++;
			zip->line++;
			zip->color_save = ft_split(zip->line, ", ", zip);
			// if (zip->row_check != 4)
			// 	break ;
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
	t_storage *check2 = (t_storage *)malloc(sizeof(t_storage));
	check2 = head->next;
	for (int i = 0; i < zip->height_size; i++)
	{
		for (int j = 0; j < zip->width_size; j++)
			zip->map[i][j] = '9';
	}
	// for(int i = 0; i < zip->height_size; i++)
	// {
		// printf("%s\n",check2->data);
		// printf("%s\n",zip->map[i]);
		// check2 = check2->next;
	// }
	i = -1;
	while (++i < zip->height_size)
	{
		j = 0;
		while (j < ft_strlen(check1->data))
		{
			if (check1->data[j] == '1' || check1->data[j] == '0' || check1->data[j] == 'N' || check1->data[j] == ' ' || check1->data[j] == '2')
				zip->map[i][j] = check1->data[j];
			j++;
		}
		check2 = check2->next;
		check1 = check1->next;
	}
	free(check1);
	free(head);
	// printf("%d %d\n",zip->width_size, zip->height_size);
}
