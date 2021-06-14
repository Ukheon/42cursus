#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->name << " attack with his " << this->Soard.getType() << std::endl;
}

HumanA::HumanA(std::string const &name, const Weapon &weapon): Soard(weapon),name(name)
{
}
