#include "lightsaber.hpp"

lightsaber::lightsaber()
{
	this->name = "light saber";
	this->damage = 30;
	this->ap_cost = 12;
}
	
lightsaber::lightsaber(const lightsaber &type)
{
	*this = type;
}

lightsaber::~lightsaber()
{
	;
}

lightsaber &lightsaber::operator=(const lightsaber &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	this->damage = type.damage;
	this->ap_cost = type.ap_cost;
	return (*this);
}

void lightsaber::attack() const
{
	std::cout << "ssinnnnnnnnnnnngggg. . . ." << std::endl;
}