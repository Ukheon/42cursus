#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
private:
	Bureaucrat();
	std::string name;
	int			grade;
public:
	class GradeTooHighException : public std::exception{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
		const char *what() const throw();
	};
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &type);
	Bureaucrat &operator=(Bureaucrat const &type);
	const std::string &getName() const;
	int			getGrade() const;
	void		increment();
	void		decrement();
	void		signForm(Form &type);
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &type);

#endif
