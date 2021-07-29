#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
class Intern {
private:
	Form *slot[3];
public:
	Intern();
	~Intern();
	class NotExistFormName : public std::exception {
		virtual const char *what() const throw();
	};
	Intern(Intern const &type);
	Intern &operator=(Intern const &type);
	Form *makeForm(std::string const formName, std::string const target);
};
#endif
