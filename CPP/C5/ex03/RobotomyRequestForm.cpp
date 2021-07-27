#include "RobotomyRequestForm.hpp"

std::string const RobotomyRequestForm::name = "RobotomyRequest";

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
:Form(RobotomyRequestForm::name, 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &type)
:Form(type), target(type.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

Form *RobotomyRequestForm::clone(std::string const &target)
{
	Form *ret = new RobotomyRequestForm(target);
	return (ret);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &type)
{
	if (this == &type)
		return (*this);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &type) const
{
	Form::execute(type);
	int flag = rand() % 2;
	std::cout << "DRrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr. . . " << std::endl;
	if (flag == 0)
		std::cout << this->target + " Robotomized SuccessFully! ! !" << std::endl;
	else
		std::cout << this->target + " Robotomized Failed. . . . " << std::endl;
}
