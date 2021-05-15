/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:32:04 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 14:32:05 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void			remain_run_cmd(t_info *info, char *buf)
{
	if (ft_strcmp(buf, "ra") == 0)
		rotate_a(info);
	else if (ft_strcmp(buf, "rb") == 0)
		rotate_b(info);
	else if (ft_strcmp(buf, "rr") == 0)
	{
		rotate_a(info);
		rotate_b(info);
	}
	else if (ft_strcmp(buf, "rra") == 0)
		reverse_rotate_a(info);
	else if (ft_strcmp(buf, "rrb") == 0)
		reverse_rotate_b(info);
	else if (ft_strcmp(buf, "rrr") == 0)
	{
		reverse_rotate_a(info);
		reverse_rotate_b(info);
	}
	else
		info->not_found = 1;
}

void			run_cmd(t_info *info, char *buf)
{
	if (ft_strcmp(buf, "sa") == 0)
		swap_a(info);
	else if (ft_strcmp(buf, "sb") == 0)
		swap_b(info);
	else if (ft_strcmp(buf, "ss") == 0)
	{
		swap_a(info);
		swap_b(info);
	}
	else if (ft_strcmp(buf, "pa") == 0)
		push_a(info);
	else if (ft_strcmp(buf, "pb") == 0)
		push_b(info);
	else
		remain_run_cmd(info, buf);
}
