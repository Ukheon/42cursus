#include "cat.hpp"

Cat::Cat()
{
	std::cout << "Consturctor Cat" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "desturctor Cat" << std::endl;

}

Cat::Cat(Cat const &type)
{
	std::cout << "CopyConsturctor Cat" << std::endl;
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
