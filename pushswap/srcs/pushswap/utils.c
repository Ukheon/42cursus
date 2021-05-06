#include "../../include/push_swap.h"

void			numcpy(t_info *info, int **arr)
{
	int			i;

	i = 0;
	if (info->flag == 0)
	{
		while (i < info->a_size)
		{
			(*arr)[i] = info->stack_a[i];
			i++;
		}
	}
	else
	{
		while (i < info->b_size)
		{
			(*arr)[i] = info->stack_b[i];
			i++;
		}
	}
}

int				bubble_sort(t_info *info, int **arr)
{
	int			i;
	int			j;
	int			temp;

	if (info->flag == 0)
	{
		numcpy(info, arr);
		i = 0;
		while (i < info->a_size)
		{
			j = 0;
			while (j < info->a_size - 1)
			{
				if ((*arr)[j] > (*arr)[j + 1])
				{
					temp = (*arr)[j];
					(*arr)[j] = (*arr)[j + 1];
					(*arr)[j + 1] = temp;
				}
				j++;
			}
			i++;
		}
		i = info->a_size / 2;
		return (i);
	}
	else
	{
		i = 0;
		numcpy(info, arr);
		while (i < info->b_size)
		{
			j = 0;
			while (j < info->b_size - 1)
			{
				if ((*arr)[j] > (*arr)[j + 1])
				{
					temp = (*arr)[j];
					(*arr)[j] = (*arr)[j + 1];
					(*arr)[j + 1] = temp;
				}
				j++;
			}
			i++;
		}
		i = info->b_size / 2;
		return (i);
	}
	return (0);
}

void			set_info(t_info *info, int argc)
{
	info->a_size = argc - 1;
	info->b_size = 0;
	info->stack_a = (int *)malloc(sizeof(int) * info->a_size);
	info->stack_b = (int *)malloc(sizeof(int) * info->a_size);
	info->check_arr = (int *)malloc(sizeof(int) * info->a_size);
	info->flag = 0;
	info->not_found = 0;
	info->remain_idx = 0;
	info->remain_arr_count[0] = info->a_size;
	info->max_argument = info->a_size;
}

int				get_argv_data(t_info *info, char *argv[])
{
	int			i;
	int			j;

	i = -1;
	j = 1;
	while (++i < info->max_argument)
	{
		if (argv_check(argv[j]))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		info->check_arr[i] = ft_atoi(argv[j]);
		info->stack_a[i] = ft_atoi(argv[j++]);
	}
	return (0);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			return (int)(str1[i] - str2[i]);
		}
		i++;
	}
	return (int)(str1[i] - str2[i]);
}

int				check_finish(t_info *info, int *arr)
{
	int			i;
	int			len;

	len = info->a_size;
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}