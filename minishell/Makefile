CC = gcc -Wall -Wextra -Werror -lncurses
TARGET = minishell

OBJS =	./gnl/get_next_line.c	\
		./srcs/shell_body.c	\
		./srcs/history.c	\
		./srcs/cursor.c	\
		./srcs/start_default.c	\
		./srcs/start_pipe.c	\
		./srcs/manage_list.c	\
		./srcs/free.c	\
		./srcs/main.c	\
		./srcs/init.c \
		./srcs/modify_list.c \
		./srcs/utils2.c \
		./srcs/error.c \
		./srcs/error2.c \
		./srcs/export_sort.c \
		./srcs/utils.c \
		./srcs/pipe_utils.c \
		./srcs/valid_check.c \
		./srcs/builtins/exec_redir.c \
		./srcs/builtins/loop_redir.c \
		./srcs/builtins/exec_cd.c \
		./srcs/builtins/exec_echo.c \
		./srcs/builtins/exec_env.c \
		./srcs/builtins/exec_exit.c \
		./srcs/builtins/exec_pwd.c \
		./srcs/builtins/exec_export.c \
		./srcs/builtins/exec_unset.c \
		./srcs/builtins/pipe_exec_cd.c \
		./srcs/not_builtins/pipe_last_builtins.c \
		./srcs/not_builtins/pipe_builtins.c \
		./srcs/not_builtins/not_builtins.c \
		./srcs/init_token.c	\
		./srcs/tokenizer.c	\
		./srcs/tokenizer_utils.c	\
		./srcs/syntax_error.c	\
		./srcs/get_cmdline.c	\
		./srcs/manufacture_token.c	\
		./srcs/redirection.c	\
		./srcs/variable_edit_utils.c	\
		./srcs/variable_edit.c	\
		./srcs/redirection_filename.c	\
		./srcs/utils3.c	\
		./srcs/syntax_quote.c \
		./srcs/remove_quote.c \
		./srcs/welcome.c


all : $(TARGET)

$(TARGET) : $(OBJS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(OBJS) -o $@ libft.a

clean :
	rm -rf $(TARGET)
	rm -rf libft.a
	rm -rf ./libft/libft.a

fclean : clean
	rm -rf $(TARGET)

re : clean all
