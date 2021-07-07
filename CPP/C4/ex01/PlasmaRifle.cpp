#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
{
	this->name = "Plasma Rifle";
	this->damage = 21;
	this->ap_cost = 5;
}
	
PlasmaRifle::PlasmaRifle(const PlasmaRifle &type)
{
	*this = type;
}

PlasmaRifle::~PlasmaRifle()
{
	;
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	this->damage = type.damage;
	this->ap_cost = type.ap_cost;
	return (*this);
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}