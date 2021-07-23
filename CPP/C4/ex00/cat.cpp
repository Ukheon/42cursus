#include "cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
}

Cat::~Cat()
{
	;
}

Cat::Cat(Cat const &type)
{
	*this = type;
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
