CC = clang++
FLAG = -Wall -Wextra -Werror
TARGET = Materia

OBJS =	main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)

re : clean all
