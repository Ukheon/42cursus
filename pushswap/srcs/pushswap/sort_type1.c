#include "../../include/push_swap.h"

void			swap_a(t_info *info)
{
	int			temp;

	if (info->a_size < 2)
		return ;
	temp = info->stack_a[0];
	info->stack_a[0] = info->stack_a[1];
	info->stack_a[1] = temp;
}

void			swap_b(t_info *info)
{
	int			temp;

	if (info->b_size < 2)
		return ;
	temp = info->stack_b[0];
	info->stack_b[0] = info->stack_b[1];
	info->stack_b[1] = temp;
}

void			numcpy_a(t_info *info, int *temp)
{
	int			i;
	int			j;

	i = 0;
	while (i < info->a_size)
	{
		info->stack_a[i] = temp[i];
		i++;
	}
}

void			numcpy_b(t_info *info, int *temp)
{
	int			i;
	int			j;

	i = 0;
	while (i < info->b_size)
	{
		// printf("%d %d\n",info->b_size, temp[i]);
		info->stack_b[i] = temp[i];
		i++;
	}
}

void			push_b(t_info *info)
{
	int			temp;
	int			i;
	int			*arr_temp;

	if (info->a_size < 1)
		return ;
	arr_temp = (int *)malloc(sizeof(int) * (info->a_size - 1));
	temp = info->stack_a[0];
	i = 0;
	while (i < info->a_size - 1)
	{
		arr_temp[i] = info->stack_a[i + 1];
		i++;
	}
	free(info->stack_a);
	info->stack_a = (int *)malloc(sizeof(int) * (info->a_size - 1));
	info->a_size--;
	numcpy_a(info, arr_temp);
	free(arr_temp);
	i = info->b_size;
	info->b_size++;
	arr_temp = (int *)malloc(sizeof(int) * (info->b_size));
	while (i > 0)
	{
		arr_temp[i] = info->stack_b[i - 1];
		i--;
	}
	arr_temp[0] = temp;
	free(info->stack_b);
	info->stack_b = (int *)malloc(sizeof(int) * (info->b_size));
	numcpy_b(info, arr_temp);
	free(arr_temp);
}

void			push_a(t_info *info)
{
	int			temp;
	int			i;
	int			*arr_temp;

	if (info->b_size < 1)
		return ;
	arr_temp = (int *)malloc(sizeof(int) * (info->b_size - 1));
	temp = info->stack_b[0];
	i = 0;
	while (i < info->b_size - 1)
	{
		arr_temp[i] = info->stack_b[i + 1];
		i++;
	}
	free(info->stack_b);
	info->stack_b = (int *)malloc(sizeof(int) * (info->b_size - 1));
	info->b_size--;
	numcpy_b(info, arr_temp);
	free(arr_temp);
	i = info->a_size;
	info->a_size++;
	arr_temp = (int *)malloc(sizeof(int) * (info->a_size));
	while (i > 0)
	{
		arr_temp[i] = info->stack_a[i - 1];
		i--;
	}
	arr_temp[0] = temp;
	free(info->stack_a);
	info->stack_a = (int *)malloc(sizeof(int) * (info->a_size));
	numcpy_a(info, arr_temp);
	free(arr_temp);
}
