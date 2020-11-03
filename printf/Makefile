C = clang

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ./ft_printf.c \
			  ./ft_get_c.c \
			  ./ft_get_p.c \
			  ./ft_get_md.c \
			  ./ft_get_md_left.c \
			  ./ft_get_md_zero.c \
			  ./ft_printf_utils.c \
			  ./ft_get_d.c \
			  ./ft_get_d_left.c \
			  ./ft_get_d_zero.c \
			  ./ft_get_x.c \
			  ./ft_get_x_left.c \
			  ./ft_get_x_zero.c \
			  ./ft_get_p_left.c \
			  ./ft_get_p_zero.c \
			  ./ft_get_s_null.c \
			  ./ft_get_s.c

OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o
