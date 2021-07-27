#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Form;
# include "Bureaucrat.hpp"

class Form
{

private:
	Form();
	std::string const &name;
	bool sign;
	int const signGrade;
	int const executeGrade;
public:
	Form(std::string const &name, int const signGrade, int const executeGrade);
	Form(Form const &type);
	virtual ~Form();
	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
	class SignCheck: public std::exception {
		virtual const char* what() const throw();
	};
	class ExecuteSignCheck: public std::exception {
		virtual const char* what() const throw();
	};
	Form &operator=(Form const &type);
	std::string const &getName(void) const;
	bool isSigned(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	void beSigned(Bureaucrat const &bureaucrat);
	virtual Form *clone(std::string const &target);
	virtual void execute(Bureaucrat const &type) const = 0;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
