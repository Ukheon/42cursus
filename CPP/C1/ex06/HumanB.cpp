#include "HumanB.hpp"

void		HumanB::attack()
{
	std::cout << this->name << " attack with his " << this->Soard->getType() << std::endl;
}

void		HumanB::setWeapon(Weapon str)
{
	this->Soard->setType(str.getType());
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}
