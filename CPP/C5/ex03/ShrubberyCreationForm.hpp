#ifndef SHRUBBERYCREATION_HPP
# define SHRUBBERYCREATION_HPP
# include "Form.hpp"
# include <fstream>

class Form;

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();
	static const std::string tree;
	const std::string target;
public:
	static const std::string name;
	ShrubberyCreationForm(ShrubberyCreationForm const &type);
	virtual ~ShrubberyCreationForm();
	class FailedOpen: public std::exception {
		virtual const char* what() const throw();
	};
	class WriteError: public std::exception {
		virtual const char* what() const throw();
	};
	ShrubberyCreationForm(std::string const &target);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &type);
	void execute(Bureaucrat const &type) const;
	Form *clone(std::string const &target);
};

#endif
