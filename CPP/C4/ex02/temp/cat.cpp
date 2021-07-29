#include "cat.hpp"

Cat::Cat()
{
	this->tmp = new Brain();
	this->type = "Cat";
}

Cat::~Cat()
{
	delete this->tmp;
}

Cat::Cat(Cat const &type)
{
	this->tmp = new Brain();
	this->type = type.type;
}

Cat &Cat::operator=(Cat const &type)
{
	for (int i = 0; i < 100; i++)
	{
		this->tmp->idea[i] = type.tmp->idea[i];
	}
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
