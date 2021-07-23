#include "dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
}

Dog::~Dog()
{
	;
}

std::string Dog::getType() const
{
	return (this->type);
}

Dog::Dog(Dog const &type)
{
	*this = type;
}

Dog &Dog::operator=(Dog const &type)
{
	this->type = type.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "meoung... meoung... arrrrrrrrrrrrrrrrrrrrrreong" << std::endl;
}
