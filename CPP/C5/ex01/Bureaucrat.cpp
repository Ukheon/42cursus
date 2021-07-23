#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	;
}

Bureaucrat::~Bureaucrat()
{
	;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low");
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	name(name)
{
	this->grade = grade;
	if (this->grade > 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	if (this->grade < 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &type)
{
	*this = type;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &type)
{
	(std::string)this->name = type.name;
	this->grade = type.grade;
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::increment()
{

	this->grade--;
	if (this->grade < 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
}

void		Bureaucrat::decrement()
{
	this->grade++;
	if (this->grade > 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &type)
{
	out << type.getName() << " bureaucrat grade " << type.getGrade();
	return (out);
}
