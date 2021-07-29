#include "animal.hpp"
Animal::Animal()
{
	std::cout << "Constructor animal" << std::endl;
	this->type = "nothing";
}

Animal::~Animal()
{
	std::cout << "destructor anmial" << std::endl;
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
