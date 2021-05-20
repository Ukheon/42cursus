/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:02:26 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/20 16:51:12 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/ioctl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <termios.h>
# include <termcap.h>
# define BACKSPACE 127
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699

typedef struct			s_var
{
	char				quote;
	int					start_idx;
	int					end_idx;
	int					quote_idx;
	int					prev;
	int					redir_len;
}						t_var;

typedef struct			s_quote
{
	char				quote;
	int					backslash;
	int					quote_end;
}						t_quote;

typedef struct			s_options
{
	int					word;
	char				option;
}						t_options;

typedef struct			s_token
{
	t_list				*redir_list;
	char				*token;
	char				*cmd;
	char				**argv;
	int					semi_flag;
	int					pipe_flag;
	int					redir_flag;
	struct s_token		*next;
}						t_token;

typedef struct			s_history
{
	char				*str;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

typedef struct			s_info
{
	long long int		col;
	long long int		row;
	long long int		c;
	char				*save_home;
	int					redir_stop;
	int					col_max;
	int					idx;
	int					his_idx;
	int					signal_flag;
	char				*cm;
	char				*ce;
	char				buf[4096];
	char				*history_temp;
	int					fd_flag;
	int					fd_storage[2];
	int					pipe_flag;
	int					redir_flag;
	int					first_flag;
	int					history_flag;
	int					write_flag;
	char				*cmd;
	char				*path_str;
	char				*oldpwd;
	char				**split;
	char				**env;
	char				**argv;
	char				*address;
	pid_t				pid;
	int					fds[2];
	int					dfs[2];
	int					status;
	int					check2;
	int					enter_flag;
	int					left_fd;
	int					right_fd;
	int					echo_flag;
	int					save_pid;
	int					error;
	int					check;
	struct termios		term;
	struct termios		default_term;
}						t_info;

t_info					g_info;

void					syntax_quote_check(char ch, t_quote *quote, \
int *i, char *str);
int						double_quote_condition_check(char ch, t_quote *quote);
int						backslash_check(char ch, t_quote *quote);
void					quote_off_check(char ch, t_quote *quote);
void					set_child_dup(void);
int						arr_row_check(char **split);
void					set_exec_data(t_list **head);
void					change_value(t_list **head, char *str, \
int flag, char *value);
int						check_valid_var(char *temp);
void					not_found_dir(t_token **tokens);
void					oldpwd_not_set(void);
int						is_valid_builtins(t_token **tokens);
int						exec_cd(t_token **tokens, t_list **head);
int						exec_cd_home(t_token **tokens, t_list **head);
int						exec_cd_prev(t_token **tokens, t_list **head);
int						exec_cd_folder(t_token **tokens, t_list **head);
void					exec_echo(t_token **tokens, int flag);
void					exec_env(t_token **tokens, t_list **head);
int						exec_exit(t_token **tokens, int num);
void					exec_pwd();
void					exec_unset(t_token **tokens, t_list **head);
int						exec_export(t_token **tokens, t_list **head, int num);
void					export_list(t_list **head, char *str, int num);
int						export_error(char *str, int num);
void					equal_exist(t_list **head, char *str, int save, \
int num);
int						export_valid_check(t_list **head, char *str, \
int save, int num);
void					default_parent(t_token **tokens);
void					default_child(t_token **tokens, t_list **head);
int						default_builtins(t_token **tokens, t_list **head);
void					minishell_start(t_list **head, t_list **history, \
t_list **temp);
int						check_char(long long int num, t_list **history);
int						loop_read_check(t_list **history, t_list **temp, \
t_list **head, char *new_line);
int						quote_error_check(char *line);
int						option_error_check(char *line);
int						right_redir_error_check(char *line);
int						left_redir_error_check(char *line);
int						new_line_error_check(char *line);
int						print_syntax_error(int syntax_part);
void					exec_history(t_list **history, int save, \
char *history_data);
int						history_error_check(t_list **history);
t_list					*new_history(char *str);
void					call_history(t_list **history);
void					init_list(t_list **head, char *envp[]);
void					init_term();
void					init_info(int num);
void					init_redir_flag(void);
int						invalid_key_check(char ch, int flag);
void					signal_handler(int signo);
int						loop_redir(t_token **tokens, int fd);
int						check_right_redir(t_token **tokens, int fd, \
char *redir);
int						check_left_redir(t_token **tokens, int fd);
void					only_exist_right(t_token **tokens, t_list **head);
int						only_exist_left(t_token **tokens, t_list **head);
void					both_exist(t_token **tokens, t_list **head);
void					token_lstdelone(t_token *lst, void (*del)(void*));
void					free_split(char **split);
t_token					*token_lstlast(t_token *lst);
t_token					*new_token(char *str);
void					token_add_back(t_token **tokens, t_token *new);
void					add_list(t_list **head, char *str, int num);
void					export_add_list(t_token **tokens, t_list **head, \
int num);
void					unset_list(t_list **head, char *str);
char					*find_home(t_list **head, char *str);
void					init_tokens(t_token **tokens);
int						numeric_error_check(t_token **tokens, int num);
int						many_argv_check(t_token **tokens, int num);
int						pipe_exec_cd(t_token **tokens, t_list **head);
void					pipe_exec_unset(t_token **tokens, t_list **head, \
int num);
void					pipe_last_builtins(t_token **tokens, t_list **head);
void					pipe_builtins(t_token **tokens, t_list **head);
void					pipe_parent(t_token **tokens);
void					env_error_message(t_token **tokens);
void					parent_wait();
void					set_fd();
void					set_pipe(t_list **head);
void					pipe_export(t_token **tokens);
void					working_token(t_token **tokens, t_list **head);
int						check_valid_var(char *temp);
char					*realloc_str(char *dst, char *src);
char					*join_char(char *dst, char src);
int						nbr_length(int n);
void					delete_end();
void					move_cursor_right();
void					move_cursor_left();
void					get_cursor_position(long long int *col, \
long long int *rows, int i, int a);
int						parse_minishell(char *line, t_list **head);
void					start_pipe(t_token **tokens, t_list **head);
void					start_default(t_token **tokens, t_list **head);
void					exec_redir(t_token **tokens, t_list **head);
int						putchar_tc(int tc);
void					check_list(t_list *head);
void					retry_seperate_redir(t_token **token, int flag, \
char *tmp_str);
void					seperate_redir(t_token **token);
char					*upper_str(char *str);
char					*find_in_env(t_list **head, char *str);
char					**fill_env_data(t_list **head);
void					change_pwd(t_list **head, char *str);
void					sub_list(t_list **head, char *str);
int						check_syntax_error(char *line);
void					big_tokenizer(char *line, t_token **tokens, \
t_list **head);
void					get_cmdline(t_token **tokens, t_list **head);
int						is_in_char(char ch, char *str);
int						ft_strcmp(const char *s1, const char *s2);
void					sort_str(char **env);
void					sort_row(char **s1, char **s2);
void					remove_quote_check(char ch, t_quote *quote);
void					quote_check(char ch, t_quote *quote);
void					exception_export(char *str);
int						is_space(char ch);
void					quote_init(t_quote *quote);
void					option_init(t_options *option);
int						check_syntax_error(char *line);
int						new_line_error_check(char *line);
int						left_redir_error_check(char *line);
int						right_redir_error_check(char *line);
int						print_new_line_error(void);
int						print_quote_syntax_error(void);
int						print_option_error(void);
int						print_left_redir_error(void);
int						print_right_redir_error(void);
int						print_syntax_error(int syntax_part);
void					init_tokenizer_flag(int *i, t_quote *quote);
t_token					*init_empty_token(t_token *token);
int						is_empty_string(char *str);
int						is_seperate_token(char *line, int i);
void					recursive_semi(char **str, t_list **head, \
char *line, int *idx);
void					wellcome_massage(void);
void					seperate_token(char **str, char *line, int *idx);
void					add_token(char **str, \
t_token **tokens, int *idx);
char					*manufacture_token(char *token, t_list **head);
void					manufacture_cmdline(t_token **tokens, t_list **head);
void					manufacture_redir_filename(t_list **redir_list);
void					seperate_redir(t_token **token);
void					retry_seperate_redir(t_token **token, \
int flag, char *tmp_str);
char					*redir_modify_token(char *str, t_var parser);
int						add_redir_list(t_token **temp, char *str);
int						variable_condition_check(char *token, \
int i, t_quote quote);
char					*except_variable(char ch);
int						check_variable_area(char ch);
int						check_invalid_variable(char *token, \
int idx, int *var_len);
char					*change_to_constant(char *token, \
int *var_len, t_list **head);
int						variable_edit(char *str, int idx, \
t_list **head, char **ret);
int						check_redir_filename(t_quote quote, char ch);
void					add_filename(t_list **redir, char *s, \
int len, t_token **token);
char					*join_char(char *dst, char src);
void					change_to_space(char *str);
void					parser_init(t_var *parser);
char					*join_str(char *dst, char *src);
int						edit_backslash(char *str, int *idx, \
t_quote quote, char **temp);
char					*loop_remove_quote(char *token);
char					*remove_quote(char *token);
void					seperate_cmdline(t_token **token);
void					erase_blank(t_token **tokens);
void					seperate_cmd(t_token **tokens);
#endif
