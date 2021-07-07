#include "AWeapon.hpp"

AWeapon::AWeapon()
{
	;
}

AWeapon::AWeapon(const AWeapon &type)
{
	*this = type;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->name = name;
	this->ap_cost = apcost;
	this->damage = damage;
}

AWeapon::~AWeapon()
{
	std::cout << "success" << std::endl;
}

AWeapon &AWeapon::operator=(const AWeapon &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	this->ap_cost = type.ap_cost;
	this->damage = type.damage;
	return (*this);
}

std::string const &AWeapon::getName() const
{
	return (this->name);
}

int			AWeapon::getAPCost() const
{
	return (this->ap_cost);
}

int			AWeapon::getDamage() const
{
	return (this->damage);
}