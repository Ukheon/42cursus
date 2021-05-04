#include "../../include/checker.h"

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

void			push_b(t_info *info)
{
	int			temp;
	int			i;

	if (info->a_size < 1)
		return ;
	temp = info->stack_a[0];
	i = 0;
	while (i < info->a_size - 1)
	{
		info->stack_a[i] = info->stack_a[i + 1];
		i++;
	}
	i = 0;
	info->a_size--;
	i = info->b_size;
	info->b_size++;
	while (i > 0)
	{
		info->stack_b[i] = info->stack_b[i - 1];
		i--;
	}
	info->stack_b[0] = temp;
}

void			push_a(t_info *info)
{
	int			temp;
	int			i;
	int			len;

	if (info->b_size < 1)
		return ;
	temp = info->stack_b[0];
	i = 0;
	while (i < info->b_size - 1)
	{
		info->stack_b[i] = info->stack_b[i + 1];
		i++;
	}
	info->b_size--;
	i = 0;
	len = info->a_size;
	info->a_size++;
	i = len;
	while (i > 0)
	{
		info->stack_a[i] = info->stack_a[i - 1];
		i--;
	}
	info->stack_a[0] = temp;
}
