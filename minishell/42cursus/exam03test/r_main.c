#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int         ft_putstr(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (1);
}

int         main(int argc, char *argv[])
{
    if (argc != 2)
        return (ft_putstr("Error: argument\n"));
	FILE *file;
	int read;
	int arr_width;
	int arr_height;
	char arr_c, c;
	char *images;
	float start_x, start_y, r_width, r_height;
	char type;
	int x;
	int y;
	if (!(file = fopen(argv[1],"r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	if ((read = fscanf(file, "%d %d %c\n", &arr_width, &arr_height, &arr_c)) != 3)
		return (ft_putstr("Error: Operation file corrupted\n"));
	if (!(arr_width > 0 && arr_width <= 300) || !(arr_height > 0 && arr_height <= 300))
		return (ft_putstr("Error: Operation file corrupted\n"));
	images = (char *)malloc(sizeof(char) * (arr_width * arr_height));
	memset(images, arr_c, arr_width * arr_height);
	read = fscanf(file, "%c %f %f %f %f %c\n", &type, &start_x, &start_y, &r_width, &r_height, &c);
	printf("%d %c\n",read, type);
	while (read == 6)
	{
		y = 0;
		if (!(type == 'r') && !(type == 'R'))
		{
			printf("here?\n");
			return (ft_putstr("Error: Operation file corrupted\n"));
		}
		while (y < arr_height)
		{
			x = 0;
			while (x < arr_width)
			{
				if (type == 'R')
				{
					if ((float)x >= start_x && (float)x <= start_x + r_width && (float)y >= start_y && (float)y <= start_y + r_height)
					{
						images[y * arr_width + x] = c;
					}
				}
				if (type == 'r')
				{	
					if ((float)x - start_x < 1.000000 || (float)y - start_y < 1.000000 || start_x + r_width - (float)x < 1.0000000 || start_y + r_height - (float)y < 1.0000000)
					{
						if ((float)x >= start_x && (float)x <= start_x + r_width && (float)y >= start_y && (float)y <= start_y + r_height)
						{
							images[y * arr_width + x] = c;
						}
					}
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %f %c\n", &type, &start_x, &start_y, &r_width, &r_height, &c);
	}
	printf("%d\n",read);
	if (read != -1)
	{
		free(images);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	y = 0;
	while (y < arr_height)
	{
		write(1, images + arr_width * y, arr_width);
		write(1, "\n", 1);
		y++;
	}

}
