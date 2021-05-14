#include "../../include/push_swap.h"
#include "../../libft/libft.h"

void			set_info(t_info *info, int argc)
{
	int			check;

	info->a_size = argc - 1;
	info->b_size = 0;
	info->stack_a = (int *)malloc(sizeof(int) * info->a_size);
	info->stack_b = (int *)malloc(sizeof(int) * info->a_size);
	info->check_arr = (int *)malloc(sizeof(int) * info->a_size);
	info->flag = 0;
	info->not_found = 0;
	info->remain_idx = 0;
	info->remain_arr_count[0] = info->a_size;
	info->max_argument = (float)info->a_size;
	check = info->max_argument / 100;
	if (check == 0)
		info->max_loop = (float)(5);
	else
	{
		if (info->max_argument >= 200)
			check += 2;
		info->max_loop = (float)(5 + check);
	}
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
			write(2, "Error\n", 6);
			return (1);
		}
		info->stack_a[i] = ft_atoi(argv[j]);
		if ((info->stack_a[i] == 0 || info->stack_a[i] == -1) && ft_strlen(argv[j]) >= 3)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		info->check_arr[i] = ft_atoi(argv[j++]);
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
