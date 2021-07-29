#include "dog.hpp"

Dog::Dog()
{
	std::cout << "Consturctor Dog" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "desturctor Dog" << std::endl;
	;
}

std::string Dog::getType() const
{
	return (this->type);
}

Dog::Dog(Dog const &type)
{
	std::cout << "CopyConsturctor dog" << std::endl;
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
