CC = gcc
CFLAG = -L ./mlx -lmlx -framework OpenGL -framework AppKit
TARGET = cub

OBJS =	./src/main.c \
		./src/ft_atoi.c \
		./src/ft_strcmp.c \
		./src/ft_split.c \
		./src/get_next_line.c \
		./src/get_next_line_utils.c \
		./src/map_check.c \
		./src/get_map_data.c \
		./src/check_player_vec.c \
		./src/calculate.c \
		./src/get_splite.c \
		./src/player_move.c \
		./src/get_img.c \
		./src/utils.c \
		./src/ft_bitmap.c \
		./src/key_flag.c \
		./src/mini_map.c
		# ./src/get_screen_size.c

all : $(TARGET)

$(TARGET) :
	make -C mlx
	$(CC) $(CFLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)
	rm -rf mlx/*.o mlx/libmlx.a

re :
	make clean
	make all
