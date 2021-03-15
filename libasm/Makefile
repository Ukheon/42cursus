NAME = libasm.a

SRCS =	./src/ft_strlen.s \
		./src/ft_strcpy.s \
		./src/ft_strcmp.s \
		./src/ft_write.s \
		./src/ft_strdup.s \
		./src/ft_read.s

OBJS = $(SRCS:.s=.o)

%.o : %.s
	nasm -f macho64 $<


$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all