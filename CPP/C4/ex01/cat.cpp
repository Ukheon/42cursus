#include "cat.hpp"

Cat::Cat()
{
	std::cout << "constructor Cat" << std::endl;
	this->tmp = new Brain();
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "destructor Cat" << std::endl;
	delete this->tmp;
}

Cat::Cat(Cat const &type)
{
	std::cout << "Copyconstructor Cat" << std::endl;
	this->tmp = new Brain();
	this->type = type.type;
}

Cat &Cat::operator=(Cat const &type)
{
	this->type = type.type;
	return (*this);
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "yaong???? yang! shoookk shooook" << std::endl;
}
