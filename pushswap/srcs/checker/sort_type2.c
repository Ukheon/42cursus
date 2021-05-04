#include "../../include/checker.h"

void			rotate_a(t_info *info)
{
	int			i;
	int			temp;
	int			len;

	len = info->a_size;
	if (len < 2)
		return ;
	i = 0;
	temp = info->stack_a[i];
	while (i < len - 1)
	{
		info->stack_a[i] = info->stack_a[i + 1];
		i++;
	}
	info->stack_a[i] = temp;
}

void			rotate_b(t_info *info)
{
	int			i;
	int			temp;
	int			len;

	len = info->b_size;
	if (len < 2)
		return ;
	i = 0;
	temp = info->stack_b[i];
	while (i < len - 1)
	{
		info->stack_b[i] = info->stack_b[i + 1];
		i++;
	}
	info->stack_b[i] = temp;
}

void			reverse_rotate_a(t_info *info)
{
	int			i;
	int			temp;
	int			len;

	len = info->a_size;
	if (len < 2)
		return ;
	i = len - 1;
	temp = info->stack_a[i];
	while (i > 0)
	{
		info->stack_a[i] = info->stack_a[i - 1];
		i--;
	}
	info->stack_a[i] = temp;
}

void			reverse_rotate_b(t_info *info)
{
	int			i;
	int			temp;
	int			len;

	len = info->b_size;
	if (len < 2)
		return ;
	i = len - 1;
	temp = info->stack_b[i];
	while (i > 0)
	{
		info->stack_b[i] = info->stack_b[i - 1];
		i--;
	}
	info->stack_b[i] = temp;
}
