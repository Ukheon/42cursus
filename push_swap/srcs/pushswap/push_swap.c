#include "../../include/push_swap.h"

void			numcpy(t_info *info, int **temp_arr)
{
	int			i;
	int			j;

	i = 0;
	j = info->start_idx;
	while (i < (int)info->pivot)
	{
		(*temp_arr)[i] = info->check_arr[j];
		j++;
		i++;
	}
}

t_arr			*lstlast(t_arr *lst)
{
	t_arr *new;

	if (!lst)
		return (0);
	new = lst;
	while (new->next)
		new = new->next;
	return (new);
}

void			lstadd_front(t_arr **lst, t_arr *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void			lstadd_back(t_arr **lst, t_arr *new)
{
	t_arr			*lstnew;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lstnew = lstlast(*lst);
	lstnew->next = new;
	new->next = NULL;
}

t_arr			*lstnew(t_info *info, int count)
{
	t_arr		*new;
	int			i;
	int			j;

	if (!(new = (t_arr *)malloc(sizeof(t_arr) * 1)))
		return (0);
	new->count = count;
	new->arr = (int *)malloc(sizeof(int) * (int)(info->pivot + 1));
	i = 0;
	j = (int)info->start_idx;
	while (i < count)
	{
		new->arr[i] = info->check_arr[j];
		j++;
		i++;
	}
	new->next = 0;
	return (new);
}

void			loop_a_to_b(t_info *info, int flag)
{
	while (1)
	{
		if (flag == 0)
		{
			if (info->pivot_value >= info->stack_a[0])
			{
				run_cmd(info, "pb\n");
				break ;
			}
		}
		else if (info->pivot_value == info->stack_a[0])
		{
			run_cmd(info, "pb\n");
			break ;
		}
		if (info->r_count <= info->rr_count)
			run_cmd(info, "ra\n");
		else
			run_cmd(info, "rra\n");
	}
}

void			case_a_three(t_info *info)
{
	if (info->stack_a[0] < info->stack_a[1] && \
	info->stack_a[1] < info->stack_a[2])
		return ;
	else if (info->stack_a[0] < info->stack_a[1] && info->stack_a[1] \
	> info->stack_a[2] && info->stack_a[2] > info->stack_a[0])
	{
		run_cmd(info, "ra\n");
		run_cmd(info, "sa\n");
		run_cmd(info, "rra\n");
	}
	else if (info->stack_a[0] > info->stack_a[1] && info->stack_a[1] \
	< info->stack_a[2] && info->stack_a[2] > info->stack_a[0])
		run_cmd(info, "sa\n");
	else if (info->stack_a[0] < info->stack_a[1] && info->stack_a[1] \
	> info->stack_a[2] && info->stack_a[2] < info->stack_a[0])
		run_cmd(info, "rra\n");
	else if (info->stack_a[0] > info->stack_a[1] && info->stack_a[1] \
	< info->stack_a[2] && info->stack_a[2] < info->stack_a[0])
		run_cmd(info, "ra\n");
	else
	{
		run_cmd(info, "sa\n");
		run_cmd(info, "rra\n");
	}
}

void			find_case_a(t_info *info)
{
	if (info->a_size == 3)
	{
		case_a_three(info);
	}
	else if (info->a_size == 2)
	{
		if (info->stack_a[0] > info->stack_a[1])
			run_cmd(info, "sa\n");		
	}
	else
		return ;
}

void			check_fast_road_b(t_info *info)
{
	int			i;

	i = -1;
	info->r_count = 0;
	info->rr_count = 0;
	while (++i < info->b_size)
	{
		if (info->pivot_value == info->stack_b[i])
			break ;
		info->r_count++;
	}
	i = info->b_size;
	while (--i >= 0)
	{
		if (info->pivot_value == info->stack_b[i])
			break;
		info->rr_count++;
	}
}

void			check_fast_road(t_info *info)
{
	int			center;
	int			remain;
	int			i;

	i = -1;
	info->r_count = 0;
	info->rr_count = 0;
	while (++i < info->a_size)
	{
		if (info->pivot_value >= info->stack_a[i])
			break;
		info->r_count++;
	}
	i = info->a_size;
	while (--i >= 0)
	{
		if (info->pivot_value >= info->stack_a[i])
			break;
		info->rr_count++;
	}
}

void			move_arr(t_info *info, t_arr **head)
{
	int			count;

	count = 0;
	info->start_idx = 0;
	info->move_loop = 1;
	while (info->move_loop != (int)(info->max_loop + 1))
	{
		info->pivot = (info->max_argument / info->max_loop) * info->move_loop - 1;
		lstadd_front(head, lstnew(info, (int)(info->pivot - info->start_idx + 1)));
		count = (int)info->pivot + 1;
		info->pivot_value = info->check_arr[(int)(info->pivot)];
		while (count - info->start_idx)
		{
			check_fast_road(info);
			loop_a_to_b(info, 0);
			count--;
		}
		info->start_idx = (int)info->pivot + 1;
		info->move_loop++;
	}
}

void			loop_b_to_a(t_info *info)
{
	while (1)
	{
		if (info->pivot_value == info->stack_b[0])
		{
			run_cmd(info, "pa\n");
			break ;
		}
		if (info->r_count < info->rr_count)
			run_cmd(info, "rb\n");
		else
			run_cmd(info, "rrb\n");
	}
}

void			sort_arr(t_info *info, t_arr **head)
{
	int			idx;
	t_arr		*temp;

	while (*head)
	{
		idx = (*head)->count;
		while (idx--)
		{
			info->pivot_value = (*head)->arr[idx];
			check_fast_road_b(info);
			loop_b_to_a(info);
		}
		temp = (*head)->next;
		free((*head)->arr);
		free((*head));
		(*head) = temp;
	}
	free((*head));
}

void			bubble(t_info *info, int **arr)
{
	int			i;
	int			j;
	int			temp;

	i = 0;
	while (i < info->max_argument)
	{
		j = 0;
		while (j < info->max_argument - 1)
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

void			optimization(t_info *info)
{
	int			i;

	i = -1;
	info->r_count = 0;
	info->rr_count = 0;
	while (++i < info->a_size)
	{
		if (info->pivot_value == info->stack_a[i])
			break;
		info->r_count++;
	}
	i = info->a_size;
	while (--i >= 0)
	{
		if (info->pivot_value == info->stack_a[i])
			break;
		info->rr_count++;
	}
}

void			find_case_b(t_info *info)
{
	int			idx;
	int			i;

	i = 0;
	idx = 2;
	while (idx--)
	{
		info->pivot_value = info->check_arr[i++];
		optimization(info);
		loop_a_to_b(info, 1);
	}
	find_case_a(info);
	run_cmd(info, "pa\n");
	run_cmd(info, "pa\n");
}

void			start_pushswap(t_info *info)
{
	int			count;
	t_arr		*head;

	head = NULL;
	info->move_loop = 0;
	bubble(info, &info->check_arr);
	if (info->max_argument <= 5)
	{
		if (info->max_argument <= 3)
			find_case_a(info);
		else
			find_case_b(info);
		return ;
	}
	while (1)
	{
		if (check_finish(info, info->stack_a) && info->b_size == 0)
		{
			return ;
		}
		move_arr(info, &head);
		sort_arr(info, &head);
	}
}

int				check_error(t_info *info)
{
	int			i;
	int			j;

	i = 0;
	while (i < info->a_size)
	{
		j = i + 1;
		while (j < info->a_size)
		{
			if (info->stack_a[i] == info->stack_a[j])
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				main(int argc, char *argv[])
{
	t_info		info;
	int			i;
	int			j;

	if (argc == 1)
		return (0);
	info.max_argument = argc - 1;
	set_info(&info, argc);
	if (get_argv_data(&info, argv))
		return (0);
	if (check_error(&info))
		return (0);
	start_pushswap(&info);
	return (0);
}
