#include "ShrubberyCreationForm.hpp"
std::string const ShrubberyCreationForm::name = "ShrubberryCreation";
std::string const ShrubberyCreationForm::tree =
			"    /\\\n" \
			"   /@@\\\n" \
			"  /@$%@\\\n" \
			" /@#$%^@\\\n" \
			"/@#$%^&*@\\\n"
			"----------\n" \
			"    ||\n"	\
			"    ||\n" ;


ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
:Form(ShrubberyCreationForm::name, 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &type)
:Form(type), target(type.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char *ShrubberyCreationForm::FailedOpen::what() const throw()
{
	return ("ShrubberyCreationFormException: cannot file open.");
}

const char *ShrubberyCreationForm::WriteError::what() const throw()
{
	return ("ShrubberyCreationFormException: Write Error");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &type)
{
	if (this == &type)
		return (*this);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &type) const
{
	Form::execute(type);
	std::string fileName = this->target + "_shrubbery";
	std::ofstream outfile(fileName, std::ios::out);
	if (!outfile.is_open())
		throw FailedOpen();
	outfile << this->tree << std::endl;
	if (outfile.bad())
	{
		outfile.close();
		throw WriteError();
	}
	outfile.close();
}
