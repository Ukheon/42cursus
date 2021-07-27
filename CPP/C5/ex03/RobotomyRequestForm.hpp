#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();
	const std::string target;
public:
	static const std::string name;
	RobotomyRequestForm(RobotomyRequestForm const &type);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	Form *clone(std::string const &target);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &type);
	void execute(Bureaucrat const &type) const;
};

#endif
