#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct	s_info 
{
	int			loop_count;
	int			a_size;
	int			b_size;
	int			center_value;
	int			center_idx;
	int			flag;
	int			*check_arr;
	int			*stack_a;
	int			*stack_b;
	int			argc;
	int			max_argument;
	int			not_found;
	int			remain_arr_count[100];
	int			remain_idx;
	int			last_remain_count;
	int			pivot;
}				t_info;

int			g_check;

void			show_stack(t_info *info);


void			five_or_less(t_info *info);
void			three_or_less(t_info *info);
void			find_case_a(t_info *info);
void			case_a_three(t_info *info);
void			get_stack_data(t_info *info);
void			init_stack(t_info *info);
void			repeat_cmd(t_info *info, int count, char *str);
int				check_finish(t_info *info, int *arr, int count);
void			remain_run_cmd(t_info *info, char *buf);
void			run_cmd(t_info *info, char *buf);
int				ft_strcmp(const char *s1, const char *s2);
int				argv_check(char *str);
void			set_info(t_info *info, int argc);
int				bubble_sort(t_info *info, int **arr, int save);
void			reverse_rotate_a(t_info *info);
void			reverse_rotate_b(t_info *info);
void			rotate_b(t_info *info);
void			rotate_a(t_info *info);
void			swap_a(t_info *info);
void			swap_b(t_info *info);
void			push_b(t_info *info);
void			push_a(t_info *info);
int				get_argv_data(t_info *info, char *argv[]);
#endif
