#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal()
{
	this->type = "nothing";
}

WrongAnimal::~WrongAnimal()
{
	;
}

WrongAnimal::WrongAnimal(WrongAnimal const &type)
{
	*this = type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &type)
{
	this->type = type.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Why making me work twice?" << std::endl;
}
