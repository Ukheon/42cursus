CC = clang++
FLAG = -Wall -Wextra -Werror
TARGET = animal

OBJS =	main.cpp \
		cat.cpp \
		dog.cpp \
		animal.cpp \
		brain.cpp

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)

re : clean all
