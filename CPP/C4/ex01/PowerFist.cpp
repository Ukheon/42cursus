#include "PowerFist.hpp"

PowerFist::PowerFist()
{
	this->name = "Power Fist";
	this->damage = 50;
	this->ap_cost = 8;
}
	
PowerFist::PowerFist(const PowerFist &type)
{
	*this = type;
}

PowerFist::~PowerFist()
{
	;
}

PowerFist &PowerFist::operator=(const PowerFist &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	this->damage = type.damage;
	this->ap_cost = type.ap_cost;
	return (*this);
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}