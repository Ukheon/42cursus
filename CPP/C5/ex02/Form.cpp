#include "Form.hpp"

Form::Form()
:name("nothing"), signGrade(150), executeGrade(1), sign(false)
{
}

Form::Form(std::string const &name, int const signGrade, int const executeGrade)
:name(name),signGrade(signGrade), executeGrade(executeGrade)
{
	this->sign = false;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &type)
:name(type.name),signGrade(type.signGrade),executeGrade(type.executeGrade)
{
	this->sign = type.sign;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}
Form::~Form()
{
	;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too Low");
}

const char *Form::SignCheck::what() const throw()
{

	return ("FormException: Already sign OK");
}

const char *Form::ExecuteSignCheck::what() const throw()
{

	return ("FormException: be not signed");
}

Form &Form::operator=(Form const &type)
{
	this->sign = type.sign;
	return (*this);
}

std::string const &Form::getName(void) const
{
	return (this->name);
}

bool Form::isSigned(void) const
{
	return (this->sign);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->executeGrade);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	else if (this->sign)
		throw Form::SignCheck();
	this->sign = true;
}

std::ostream &operator<<(std::ostream &out, Form const &type)
{
	std::string temp;
	if (type.isSigned())
		temp = "signed";
	else
		temp = "unsigned";
	out << type.getName() + " " + temp + " signGrade : " << type.getSignGrade()
	<< " executeGrade : " << type.getExecuteGrade();
	return (out);
}

void Form::execute(const Bureaucrat &type) const
{
	if (type.getGrade() > this->executeGrade)
		throw Form::GradeTooLowException();
	if (!this->sign)
		throw Form::ExecuteSignCheck();
}
