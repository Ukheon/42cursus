CC = gcc
CFLAG = -L ./mlx -lmlx -framework OpenGL -framework AppKit
TARGET = cub3d

OBJS =	./src/cub3d.c

all : $(TARGET)

$(TARGET) :
	$(CC) $(CFLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

re :
	rm -rf $(TARGET) && make
