CC = clang++ 
FLAG = -Wall -Wextra -Werror
TARGET = Pony

OBJS =	main.cpp \
		Pony.cpp

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)

re : clean all
