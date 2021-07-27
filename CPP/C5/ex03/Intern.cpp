#include "Intern.hpp"

Intern::Intern()
{
	this->slot[0] = new ShrubberyCreationForm("ShrubberyCreation");
	this->slot[1] = new RobotomyRequestForm("RobotomyRequest");
	this->slot[2] = new PresidentialPardonForm("PresidentialPardon");
}
Intern::~Intern()
{
	for (int i = 0; i < 3; i++)
		delete this->slot[i];
}
Intern::Intern(Intern const &type)
{
	*this = type;
}
Intern &Intern::operator=(Intern const &type)
{
	if (this == &type)
		return (*this);
	return (*this);
}

const char *Intern::NotExistFormName::what() const throw()
{
	return ("InternExeception: Not Exist");
}

Form *Intern::makeForm(std::string const formName, std::string const target)
{
	Form *ret;
	for (int i = 0; i < 3; i++)
	{
		if (this->slot[i]->getName() == formName)
		{
			std::cout << "Intern Create" << std::endl;
			ret = this->slot[i]->clone(target);
			return (ret);
		}
	}
	throw Intern::NotExistFormName();
}
