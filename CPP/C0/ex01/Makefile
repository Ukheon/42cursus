CC = clang++ std=c++98
FLAG = -Wall -Wextra -Werror
TARGET = phonenumber

OBJS =	phonenumber.cpp

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FALG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)

re : clean all
