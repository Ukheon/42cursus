/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:59:25 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/15 15:59:38 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct		s_arr
{
	int				*arr;
	int				count;
	struct s_arr	*next;
}					t_arr;

typedef struct		s_info
{
	int				a_size;
	int				b_size;
	int				center_value;
	int				center_idx;
	int				flag;
	int				*check_arr;
	int				*stack_a;
	int				*stack_b;
	int				argc;
	int				max_argument;
	int				not_found;
	int				remain_arr_count[100];
	int				remain_idx;
	int				last_remain_count;
	float			pivot;
	int				pivot_value;
	int				move_loop;
	int				start_idx;
	int				r_count;
	int				rr_count;
	float			max_loop;
	long long int	num_error;
}					t_info;

void				bubble(t_info *info, int **arr);
void				loop_b_to_a(t_info *info);
void				loop_a_to_b(t_info *info, int flag);
void				find_case_b(t_info *info);
void				find_case_a(t_info *info);
void				case_a_three(t_info *info);
void				optimization(t_info *info);
void				check_fast_road_b(t_info *info);
void				check_fast_road_a(t_info *info);
void				numcpy(t_info *info, int **temp_arr);
int					check_error(t_info *info);
t_arr				*lstnew(t_info *info, int count);
void				lstadd_front(t_arr **lst, t_arr *new);
t_arr				*lstlast(t_arr *lst);
void				show_stack(t_info *info);
int					check_finish(t_info *info, int *arr);
void				remain_run_cmd(t_info *info, char *buf);
void				run_cmd(t_info *info, char *buf);
int					ft_strcmp(const char *s1, const char *s2);
int					argv_check(char *str);
void				set_info(t_info *info, int argc);
void				reverse_rotate_a(t_info *info);
void				reverse_rotate_b(t_info *info);
void				rotate_b(t_info *info);
void				rotate_a(t_info *info);
void				swap_a(t_info *info);
void				swap_b(t_info *info);
void				push_b(t_info *info);
void				push_a(t_info *info);
int					get_argv_data(t_info *info, char *argv[]);
#endif
