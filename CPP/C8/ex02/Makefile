CC = clang++
FLAG = -Wall -Wextra -Werror
TARGET = a.out

OBJS =	main.cpp \
		mutantstack.cpp

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean

re : clean all
