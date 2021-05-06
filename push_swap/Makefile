CC = gcc

PUSH = push_swap
CHECK = checker

OBJS =	./srcs/pushswap/push_swap.c \
		./srcs/pushswap/error_check.c \
		./srcs/pushswap/sort_type1.c \
		./srcs/pushswap/sort_type2.c \
		./srcs/pushswap/utils.c \
		./srcs/pushswap/run_cmd.c \
		./srcs/pushswap/three_or_less.c \
		./srcs/pushswap/five_or_less.c

COBJS = ./srcs/checker/checker.c \
		./srcs/checker/error_check.c \
		./srcs/checker/sort_type1.c \
		./srcs/checker/sort_type2.c \
		./srcs/checker/utils.c \
		./srcs/checker/run_cmd.c


all : $(PUSH)

$(PUSH) : $(OBJS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(OBJS) -o $@ libft.a

checker : $(CHECK)

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
	rm -rf $(CHECK)
	rm -rf $(PUSH)

re : clean all
