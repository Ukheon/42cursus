#include "PresidentialPardonForm.hpp"

std::string const PresidentialPardonForm::name = "PresidentialPardon";

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
:Form(PresidentialPardonForm::name, 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &type)
:Form(type), target(type.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &type)
{
	if (this == &type)
		return (*this);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &type) const
{
	Form::execute(type);
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
