CC = clang++
FLAG = -Wall -Wextra -Werror
TARGET = replace

OBJS = main.cpp

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FALG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)
	rm -rf txt.replace

re : clean all
