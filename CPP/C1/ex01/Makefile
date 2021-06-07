CC = clang++ 
FLAG = -Wall -Wextra -Werror
TARGET = ex01

OBJS =	ex01.cpp

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)

re : clean all
