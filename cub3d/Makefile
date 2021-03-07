CC = gcc -Wall -Wextra -Werror
CFLAG = -L ./mlx -lmlx -framework OpenGL -framework AppKit
TARGET = cub3D

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
		./src/mini_map.c \
		./src/cub_error.c \
		./src/textures_error.c

all : $(TARGET)

.c.o :
	$(CC) $(CFLAG) -c -o $@ $<

$(TARGET) :
	make -C mlx
	make -C mlx2
	cp ./mlx2/libmlx.dylib .
	$(CC) $(CFLAG) $(OBJS) -o $@ libmlx.dylib

clean :
	rm -rf $(TARGET)
	rm -rf mlx2/*.o mlx2/libmlx.dylib
	rm -rf mlx/*.o mlx/libmlx.a
	rm -rf ./libmlx.dylib
	rm -rf ./screenshot.bmp

fclean : clean
	rm -rf cub3D

re : clean all
