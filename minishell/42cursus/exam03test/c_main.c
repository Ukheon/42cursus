#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int				ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

int				main(int argc, char *argv[])
{
	if (argc != 2)
		return (ft_putstr("Error: argument\n"));
	FILE *file;
	int read;
	int arr_width, arr_height, x, y;
	char arr_c, c, type;
	float center_x, center_y, r;
	float dist;
	char *images;
	if (!(file = fopen(argv[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	if ((read = fscanf(file, "%d %d %c\n", &arr_width, &arr_height, &arr_c)) != 3)
		return (ft_putstr("Error: Operation file corrupted\n"));
	if (!(arr_width > 0 && arr_width <= 300) || !(arr_height > 0 && arr_height <= 300))
		return (ft_putstr("Error: Operation file corrupted\n"));
	images = (char *)malloc(sizeof(char) * arr_width * arr_height);
	read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c);
	memset(images, arr_c, arr_width * arr_height);
	while (read == 5)
	{
		printf("here?\n");
		if (!(type == 'C') && !(type == 'c'))
		{	
			return (ft_putstr("Error: Operation file corrupted\n"));
		}
		y = 0;
		while (y < arr_height)
		{
			x = 0;
			while (x < arr_width)
			{
				dist = sqrtf(powf(center_x - (float)x, 2.0) + powf(center_y - (float)y, 2.0));
				if (type == 'c')
				{
					if (r - dist < 1.0000)
					{
						if (r > dist)
							images[y * arr_width + x] = c;
					}
				}
				if (type == 'C')
				{
					if (r > dist)
						images[y * arr_width + x] = c;
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c);
	}
	if (read != -1)
	{	free(images);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	y = 0;
	while (y < arr_height)
	{
		write(1, images + y * arr_width, arr_width);
		write(1, "\n", 1);
		y++;
	}
	free(images);
	fclose(file);
	return (0);
}
