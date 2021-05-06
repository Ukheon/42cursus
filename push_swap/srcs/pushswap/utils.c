#include "../../include/push_swap.h"

void			numcpy(t_info *info, int **arr, int save, int *src)
{
	int			i;

	i = 0;
	while (i < save)
	{
		(*arr)[i] = src[i];
		i++;
	}
}

int				bubble_sort(t_info *info, int **arr, int save)
{
	int			i;
	int			j;
	int			temp;

	if (info->flag == 0) // A일때
	{
		numcpy(info, arr, save, info->stack_a);
		i = 0;
		while (i < save)
		{
			j = 0;
			while (j < save - 1)
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
	}
	else
	{
		numcpy(info, arr, save, info->stack_b);
		i = 0;
		while (i < save)
		{
			j = 0;
			while (j < save - 1)
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
	info->loop_count = 1;
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

////



int				check_finish(t_info *info, int *arr, int count)
{
	int			i;
	int			len;

	len = count;
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void			init_stack(t_info *info)
{
	int			i;

	i = 0;
	while (i < info->max_argument)
	{
		info->check_arr[i] = 0;
		i++;
	}
}

void			repeat_cmd(t_info *info, int count, char *str)
{
	int			i;

	i = 0;
	while (i < count)
	{
		run_cmd(info, str);
		i++;
	}
}

void			get_stack_data(t_info *info)
{
	int			i;

	i = 0;
	init_stack(info);
	while (i < info->remain_arr_count[info->remain_idx])
	{
		if (info->flag == 0)
			info->check_arr[i] = info->stack_a[i];
		else
			info->check_arr[i] = info->stack_b[i];
		i++;
	}
}

void			show_stack(t_info *info)
{
	int			i;
	int			j;
	int			temp;

	i = 0;
	temp = info->a_size;
	if (temp < info->b_size)
		temp = info->b_size;
	while (i < temp)
	{
		printf(" %d  |", i);
		if (info->a_size > i)
			printf("  %d|", info->stack_a[i]);
		else
			printf("    |");
		if (info->b_size > i)
			printf("   %d|", info->stack_b[i]);
		printf("\n");
		i++;
	}
	printf("\nidx |  A  |  B  |\n");
}
