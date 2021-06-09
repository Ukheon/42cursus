#include "ZombieHorde.hpp"

void			Zombie::announce()
{
	std::cout << "<" + this->name + " (" + this->type + ")> Braiiiiiiinnnssss..." << std::endl;
}

Zombie::Zombie()
{
	;
}

Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
}
Zombie::~Zombie()
{
	std::cout << this->name << " die..." << std::endl; 
}