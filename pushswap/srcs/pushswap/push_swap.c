#include "../../include/push_swap.h"

int			g_check;

// void			init_stack(t_info *info)
// {
// 	int			i;

// 	i = 0;
// 	while (i < info->max_argument)
// 	{
// 		info->check_arr[i] = 0;
// 		i++;
// 	}
// }

// void			b_to_a(t_info *info)
// {
// 	int			i;
// 	int			check;

// 	i = 0;
// 	init_stack(info);
// 	info->center_idx = bubble_sort(info, &info->check_arr);
// 	info->center_value = info->check_arr[info->center_idx];
// 	info->remain_arr_count[info->remain_idx] = info->center_idx;
// 	info->last_remain_count = info->center_idx;
// 	while (info->center_idx > 0)
// 	{
// 		check = info->b_size;
// 		while (check)
// 		{
// 			if (info->center_value > info->stack_b[i])
// 			{
// 				run_cmd(info, "pa\n");
// 				break ;
// 			}
// 			run_cmd(info, "rb\n");
// 			check--;
// 		}
// 		info->center_idx--;
// 	}
// }

// void			a_to_b(t_info *info)
// {
// 	int			i;
// 	int			check;

// 	i = 0;
// 	init_stack(info);
// 	info->center_idx = bubble_sort(info, &info->check_arr);
// 	info->center_value = info->check_arr[info->center_idx];
// 	info->remain_arr_count[info->remain_idx] = info->center_idx;
// 	info->last_remain_count = info->center_idx;
// 	while (info->center_idx > 0)
// 	{
// 		check = info->a_size;
// 		while (check)
// 		{
// 			if (info->center_value > info->stack_a[i])
// 			{
// 				run_cmd(info, "pb\n");
// 				break ;
// 			}
// 			run_cmd(info, "ra\n");
// 			check--;
// 		}
// 		info->center_idx--;
// 	}
// }

// void			div_half(t_info *info)
// {
// 	if (info->flag == 0) // 시작이 A
// 	{
// 		a_to_b(info);
// 	}
// 	else // 시작이 B
// 	{
// 		b_to_a(info);
// 	}
// }

// void			get_stack_data(t_info *info)
// {
// 	int			i;

// 	i = 0;
// 	init_stack(info);
// 	while (i < info->remain_arr_count[info->remain_idx])
// 	{
// 		if (info->flag == 0)
// 			info->check_arr[i] = info->stack_a[i];
// 		else
// 			info->check_arr[i] = info->stack_b[i];
// 		i++;
// 	}
// }

// void			case_a_three(t_info *info)
// {
// 	if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] < info->check_arr[2])
// 	{
// 		return ;
// 	}
// 	else if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] > info->check_arr[2])
// 	{
// 		run_cmd(info, "sa\n");
// 		run_cmd(info, "ra\n");
// 	}
// 	else if (info->check_arr[0] > info->check_arr[1] && info->check_arr[1] < info->check_arr[2])
// 		run_cmd(info, "sa\n");
// 	else if (info->check_arr[0] < info->check_arr[1] && info->check_arr[1] > info->check_arr[2])
// 		run_cmd(info, "rra\n");
// 	else if (info->check_arr[0] > info->check_arr[1] && info->check_arr[1] < info->check_arr[2])
// 		run_cmd(info, "ra\n");
// 	else
// 	{
// 		run_cmd(info, "ra\n");
// 		run_cmd(info, "ra\n");
// 	}
// }

// void			count_ra(t_info *info, int count)
// {
// 	int			i;

// 	i = 0;
// 	while (i < count)
// 	{
// 		run_cmd(info, "ra\n");
// 		i++;
// 	}
// }

// void			find_case_a(t_info *info)
// {
// 	printf("herere?\n");
// 	if (info->remain_arr_count[info->remain_idx] == 3)
// 	{
// 		printf("g_check = %d\n",g_check);
// 		case_a_three(info);
// 		count_ra(info, 3);
// 	}
// 	if (info->remain_arr_count[info->remain_idx] == 2)
// 	{
// 		if (info->check_arr[0] > info->check_arr[1])
// 			run_cmd(info, "sa\n");
// 		count_ra(info, 2);
// 	}
// 	if (info->remain_arr_count[info->remain_idx] == 1)
// 		count_ra(info, 1);
// }

// void			three_or_less(t_info *info)
// {
// 	int			i;

// 	i = 0;
// 	get_stack_data(info);
// 	if (info->flag == 0)
// 	{
// 		find_case_a(info);
// 	}
// }

// void			five_or_less(info)
// {
	
// }

// void			move_half_arr(t_info *info)
// {
// 	g_check++;
// 	printf("여기는 [%d]번째 idx = %d,flag = %d\n",g_check, info->remain_idx, info->flag);
// 	if (info->remain_arr_count[info->remain_idx] <= 5)
// 	{
// 		if (info->remain_arr_count[info->remain_idx] <= 3)
// 		{
// 			three_or_less(info);
// 		}
// 		else
// 		{
// 			five_or_less(info);
// 		}
// 		if (info->remain_idx > 0)
// 			info->remain_idx--;
// 	}
// 	else
// 	{
// 		info->remain_idx++;
// 		div_half(info);
// 	}
// 	if (info->flag == 0)
// 		info->flag = 1;
// 	else
// 		info->flag = 0;
// }

void			numcpy(t_info *info, int **temp_arr)
{
	int			i;
	int			j;

	i = 0;
	j = info->start_idx;
	printf("check3! = %d \n", info->start_idx);
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

void			check_fast_road_b(t_info *info)
{
	int			center;
	int			remain;
	int			i;

	i = -1;
	remain = 0;
	center = info->b_size / 2 - 1;
	info->r_count = 0;
	info->rr_count = 0;
	if (info->b_size % 2 == 1)
		remain = 1;
	while (++i < center)
	{
		if (info->pivot_value >= info->stack_b[i])
			break ;
		info->r_count++;
	}
	i = (center * 2 + remain);
	while (--i >= center)
	{
		if (info->pivot_value >= info->stack_b[i])
			break;
		info->rr_count++;
	}
	printf("%d\nr = %d vs rr = %d\n",info->pivot_value, info->r_count, info->rr_count);
}

void			check_fast_road(t_info *info)
{
	int			center;
	int			remain;
	int			i;

	i = -1;
	remain = 0;
	center = info->a_size / 2 - 1;
	info->r_count = 0;
	info->rr_count = 0;
	if (info->a_size % 2 == 1)
		remain = 1;
	while (++i < center)
	{
		if (info->pivot_value >= info->stack_a[i])
			break;
		info->r_count++;
	}
	i = (center * 2 + remain);
	while (--i >= center)
	{
		if (info->pivot_value >= info->stack_a[i])
			break;
		info->rr_count++;
	}
}

void			move_arr(t_info *info, t_arr **head)
{
	int			count;
	int			count2;

	count2 = 10;
	count = 0;
	info->start_idx = 0;
	info->move_loop = 1;
	// 3 7 11 15 19;
	while (info->move_loop != 6)
	{
		info->pivot = (info->max_argument / 5.0) * info->move_loop - 1;
		lstadd_front(head, lstnew(info, (int)(info->pivot - info->start_idx + 1)));
		// for (int i = 0; i < (int)info->pivot - info->start_idx + 1; i++)
		// 	printf("arr = [%d]\n", (*head)->arr[i]);
		// printf("check! = %f\n",info->pivot - info->start_idx + 1);
		count = (int)info->pivot + 1;
		info->pivot_value = info->check_arr[(int)(info->pivot)];
		// printf("count = %d value = %d\n", count, info->pivot_value);
		while (count - info->start_idx)
		{
			check_fast_road(info);
			// printf("start!\n");
			while(1)
			{
				// printf("================ value = [%d] a = [%d]\n",info->pivot_value, info->stack_a[0]);
				if (info->pivot_value >= info->stack_a[0])
				{
					// printf("================ %d\n", info->stack_a[0]);
					run_cmd(info, "pb\n");
					break;
				}
				if (info->r_count <= info->rr_count)
					run_cmd(info, "ra\n");
				else
					run_cmd(info, "rra\n");
			}
			count--;
		}
		info->start_idx = (int)info->pivot + 1;
		info->move_loop++;
	}
	// exit(0);
	// t_arr *temp1;

	// temp1 = *head;
	// while (temp1)
	// {
	// 	printf("%d\n", temp1->count);
	// 	for (int i = 0; i < temp1->count; i++)
	// 		printf("i = [%d] value = [%d]  ",i, temp1->arr[i]);
	// 	printf("\n");
	// 	temp1 = temp1->next;
	// }
	// for (int i = 0; i < info->b_size; i++)
	// {
	// 	printf("%d ", info->stack_b[i]);
	// }
	// printf("\n");
	// exit(0);
}

void			sort_arr(t_info *info, t_arr **head)
{
	t_arr		*temp;
	t_arr		*temp2;
	int			idx;
	int			count;

	// for(int i = 0; i < info->b_size; i++)
	// 	printf("%d ", info->stack_b[i]);
	// printf("\n");
	count = 5;
	// exit (0);
	while (*head)
	{
		idx = (*head)->count;
		while (idx--)
		{
			info->pivot_value = (*head)->arr[idx];
			// printf("%d\n", info->pivot_value);
			check_fast_road_b(info);
			while (1)
			{
				if (info->pivot_value == info->stack_b[0])
				{
					run_cmd(info, "pa\n");
					break ;
				}
				if (info->r_count <= info->rr_count)
				{
					run_cmd(info, "rb\n");
				}
				else
				{
					run_cmd(info, "rrb\n");			
				}
			}
		}
		*head = (*head)->next;
	}
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

void			start_pushswap(t_info *info)
{
	int			count;
	t_arr		*head;

	head = NULL;
	info->move_loop = 0;
	count = 8;
	bubble(info, &info->check_arr);
	// for (int i = 0; i < info->a_size; i++)
	// {
	// 	printf("%d ", info->check_arr[i]);
	// }
	// printf("   !!!end!!!\n");
	while (1)
	{
		if (check_finish(info, info->stack_a) && info->b_size == 0)
		{
			exit(0);
		}
		move_arr(info, &head);
		// exit(0);
		sort_arr(info, &head);
		// printf("herererere?\n");
		// for(int i = 0; i < info->b_size; i++)
		// {
		// 	printf("%d\n", info->stack_b[i]);
		// }
		// show_stack(info);
	}
}

int				main(int argc, char *argv[])
{
	t_info		info;
	int			i;
	int			j;

	g_check = 0;
	if (argc == 1)
		return (0);
	info.max_argument = argc - 1;
	set_info(&info, argc);
	if (get_argv_data(&info, argv))
		return (0);
	start_pushswap(&info);
	return (0);
}
