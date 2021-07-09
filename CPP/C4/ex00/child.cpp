#include "child.hpp"

child::child(std::string name)
: Victim(name)
{
	this->name = name;
	std::cout << "child called name : " + this->name + " create!" << std::endl;
}

child::child(const child &type)
{
	*this = type;
	
}

void	child::getPolymorphed() const
{
	std::cout << this->name + " has been turned into a dragon (Oh.. nice!)" << std::endl;
}

child::~child()
{
	std::cout << "child " + this->name + " delete! ! !" << std::endl;
}

child &child::operator=(const child &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	return (*this);
}

std::string child::callText() const
{
	std::string message = "I'm " + this->name + " and I like otters!";
	return (message);
}

std::ostream &operator << (std::ostream &out, const child &type)
{
	out << type.callText() << std::endl;
	return (out);
}