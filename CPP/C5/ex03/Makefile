CC = clang++
FLAG = -Wall -Wextra -Werror
TARGET = a.out

OBJS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)

re : clean all
