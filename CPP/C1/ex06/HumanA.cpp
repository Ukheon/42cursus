#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->name << " attack with his " << this->Soard->getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &str)
{
	this->name = name;
	this->Soard = &str;
}
