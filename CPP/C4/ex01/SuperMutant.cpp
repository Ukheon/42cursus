#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	this->hp = 170;
	this->type = "SuperMutant";
}

SuperMutant::SuperMutant(const SuperMutant &type)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	*this = type;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

// std::string const &SuperMutant::getType() const
// {
// 	return (this->type);
// }

// int			SuperMutant::getHP() const
// {
// 	return (this->hp);
// }

SuperMutant &SuperMutant::operator=(SuperMutant const &type)
{
	if (this == &type)
		return (*this);
	this->hp = type.hp;
	this->type = type.type;
	return (*this);
}

void SuperMutant::takeDamage(int damage)
{
	this->hp -= (damage - 3);
	if (this->hp < 0)
		this->hp = 0;
}