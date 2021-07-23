#include "wrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	;
}

WrongCat::WrongCat(WrongCat const &type)
{
	*this = type;
}

WrongCat &WrongCat::operator=(WrongCat const &type)
{
	this->type = type.type;
	return (*this);
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void WrongCat::makeSound() const
{
	std::cout << "--------------===== mammmm . . . mammmmm .  . too hot.." << std::endl;
}
