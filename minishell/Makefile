CC = gcc
TARGET = a.out

OBJS =	get_next_line.c \
		get_next_line_utils.c \
		main.c
		

all : $(TARGET)

$(TARGET) : $(OBJS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(OBJS) -o $@ libft.a

clean :
	rm -rf $(TARGET)
	rm -rf libft.a

fclean : clean
	rm -rf $(TARGET)

re : clean all
