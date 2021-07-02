#include "child.hpp"

child::child(std::string name)
{
	this->name = name;
	std::cout << "Some random victim called " + this->name + " just apperared!" << std::endl;
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
	std::cout << "Victim " + this->name + " just died for no apparent reason!";
}

child &child::operator=(const child &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	return (*this);
}