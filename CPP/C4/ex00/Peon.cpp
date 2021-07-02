#include "Peon.hpp"

Peon::Peon(std::string name)
{
	this->name = name;
	std::cout << "Some random victim called " + this->name + " just apperared!" << std::endl;
}

Peon::Peon(const Peon &type)
{
	*this = type;
	
}

void	Peon::getPolymorphed() const
{
	std::cout << this->name + " has been turned into a pink pony" << std::endl;
}

Peon::~Peon()
{
	std::cout << "Victim " + this->name + " just died for no apparent reason!";
}

Peon &Peon::operator=(const Peon &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	return (*this);
}