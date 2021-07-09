#include "zombie.hpp"

zombie::zombie()
{
	std::cout << "grrr grrr . . grrrr . . . grrr" << std::endl;
	this->hp = 1000;
	this->type = "zombie";
	this->flag = 0;
}

zombie::zombie(const zombie &type)
{
	std::cout << "grrr grrr . . grrrr . . . grrr" << std::endl;
	*this = type;
}

zombie::~zombie()
{
	std::cout << "never dddiiiiiiieeeeee . . . ." << std::endl;
}

zombie &zombie::operator=(zombie const &type)
{
	if (this == &type)
		return (*this);
	this->hp = type.hp;
	this->type = type.type;
	return (*this);
}

void zombie::takeDamage(int damage)
{
	this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}