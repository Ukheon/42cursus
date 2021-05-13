#include "../../include/push_swap.h"

void			remain_run_cmd(t_info *info, char *buf)
{
	if (ft_strcmp(buf, "ra") == 10)
		rotate_a(info);
	else if (ft_strcmp(buf, "rb") == 10)
		rotate_b(info);
	else if (ft_strcmp(buf, "rr") == 10)
	{
		rotate_a(info);
		rotate_b(info);
	}
	else if (ft_strcmp(buf, "rra") == 10)
		reverse_rotate_a(info);
	else if (ft_strcmp(buf, "rrb") == 10)
		reverse_rotate_b(info);
	else if (ft_strcmp(buf, "rrr") == 10)
	{
		reverse_rotate_a(info);
		reverse_rotate_b(info);
	}
	else
		info->not_found = 1;
}

void			run_cmd(t_info *info, char *buf)
{
	info->not_found = 0;
	if (ft_strcmp(buf, "sa") == 10)
		swap_a(info);
	else if (ft_strcmp(buf, "sb") == 10)
		swap_b(info);
	else if (ft_strcmp(buf, "ss") == 10)
	{
		swap_a(info);
		swap_b(info);
	}
	else if (ft_strcmp(buf, "pa") == 10)
		push_a(info);
	else if (ft_strcmp(buf, "pb") == 10)
		push_b(info);
	else
		remain_run_cmd(info, buf);
	if (info->not_found != 1)
		write(1, buf, ft_strlen(buf));
	else
		info->not_found = 0;
}
