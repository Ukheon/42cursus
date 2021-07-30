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
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
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

const std::string &Bureaucrat::getName() const
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

void Bureaucrat::signForm(Form &type)
{
	if (type.isSigned())
		std::cout << this->name << " can not sign " << type.getName() << " because it`s form is already signed!" << std::endl;
	else
	{
		try
		{
			type.beSigned(*this);
			std::cout << this->name << " signs " << type.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << this->name << " can not signs " << type.getName() << " because " << e.what() << std::endl;
		}
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &type)
{
	out << type.getName() << " bureaucrat grade " << type.getGrade();
	return (out);
}
