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
	*this = type;
}

Cat &Cat::operator=(Cat const &type)
{
	std::cout << "Cat operator called" << std::endl;
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
