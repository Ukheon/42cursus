#include "dog.hpp"

Dog::Dog()
{
	std::cout << "constructor Dog" << std::endl;
	this->tmp = new Brain();
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "destructor Dog" << std::endl;
	delete this->tmp;
}

std::string Dog::getType() const
{
	return (this->type);
}

Dog::Dog(Dog const &type)
{
	std::cout << "Copyconsturctor Dog" << std::endl;
	this->tmp = new Brain();
	*this = type;
}

Dog &Dog::operator=(Dog const &type)
{
	std::cout << "Dog operator called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->tmp->idea[i] = type.tmp->idea[i];
	}
	this->type = type.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "meoung... meoung... arrrrrrrrrrrrrrrrrrrrrreong" << std::endl;
}
