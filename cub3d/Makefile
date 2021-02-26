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
		./src/utils.c
		# ./src/ft_strdup.c \
		# ./src/ft_strlcpy.c

all : $(TARGET)

$(TARGET) :
	#make -C mlx
	#make -C mlx2
	cp mlx2/libmlx.dylib .
	$(CC) $(CFLAG) $(OBJS) -o $@  && ./$(TARGET)

clean :
	rm -rf $(TARGET)
	rm -rf mlx/*.o mlx/libmlx.a
	rm -rf mlx2/*.o mlx/libmlx.dylib
	rm -rf libmlx.dylib

re :
	make clean
	make all
