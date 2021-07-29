#include "animal.hpp"
Animal::Animal()
{
	std::cout << "constructor Animal" << std::endl;
	this->type = "nothing";
}

Animal::~Animal()
{
	std::cout << "destructor Animal" << std::endl;
}

Animal::Animal(Animal const &type)
{
	std::cout << "CopyConstructor Animal" << std::endl;
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
