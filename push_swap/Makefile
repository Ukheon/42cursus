CC = gcc -Wall -Wextra -Werror

PUSH = push_swap
CHECK = checker

OBJS =	./srcs/pushswap/push_swap.c \
		./srcs/pushswap/error_check.c \
		./srcs/pushswap/sort_type1.c \
		./srcs/pushswap/sort_type2.c \
		./srcs/pushswap/utils.c \
		./srcs/pushswap/utils2.c \
		./srcs/pushswap/run_cmd.c \
		./srcs/pushswap/optimization.c \
		./srcs/pushswap/list.c \
		./srcs/pushswap/less_than_five.c

COBJS = ./srcs/checker/checker.c \
		./srcs/checker/error_check.c \
		./srcs/checker/sort_type1.c \
		./srcs/checker/sort_type2.c \
		./srcs/checker/utils.c \
		./srcs/checker/run_cmd.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c


all : $(PUSH)

$(PUSH) : $(OBJS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(OBJS) -o $@ libft.a

bonus : $(CHECK)

$(CHECK) : $(COBJS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(COBJS) -o $@ libft.a

clean :
	rm -rf $(TARGET)
	rm -rf $(PUSH)
	rm -rf libft.a
	rm -rf ./libft/libft.a


fclean : clean
	rm -rf ./libft/*.o
	rm -rf $(CHECK)
	rm -rf $(PUSH)

re : clean all
