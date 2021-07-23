#include "animal.hpp"
Animal::Animal()
{
	this->type = "nothing";
}

Animal::~Animal()
{
	;
}

Animal::Animal(Animal const &type)
{
	*this = type;
}

Animal &Animal::operator=(Animal const &type)
{
	this->type = type.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "nothing . . . " << std::endl;
}
