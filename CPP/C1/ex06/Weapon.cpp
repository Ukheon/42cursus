#include "Weapon.hpp"



Weapon::Weapon(std::string str)
{
	this->Type = str;
}

const std::string	&Weapon::getType()
{
	return (this->Type);
}

void	Weapon::setType(std::string type)
{
	this->Type = type;
}

Weapon::Weapon(){

}
