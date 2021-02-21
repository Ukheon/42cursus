CC = gcc
CFLAG = -L ./mlx -lmlx -framework OpenGL -framework AppKit
TARGET = cub3d

OBJS =	./src/cub3d.c \
		./src/ft_atoi.c \
		./src/ft_strcmp.c \
		./src/ft_split.c \
		./src/get_next_line.c \
		./src/get_next_line_utils.c
		# ./src/ft_strdup.c \
		# ./src/ft_strlcpy.c

all : $(TARGET)

$(TARGET) :
	$(CC) $(CFLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

re :
	rm -rf $(TARGET) && make
