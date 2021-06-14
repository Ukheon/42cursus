#include "Weapon.hpp"

Weapon::Weapon(std::string const str)
{
	this->Type = str;
}

const std::string	&Weapon::getType() const
{
	return (this->Type);
}

void		Weapon::setType(std::string type)
{
	this->Type = type;
}

Weapon::Weapon(){

}
