#include "ZombieEvent.hpp"

Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie *res;

	res = new Zombie(name, this->type);
	return (res);
}

std::string ZombieEvent::getZombieType()
{
	return (this->type);
}

void	ZombieEvent::setZombieType(std::string input)
{
	this->type = input;
}

std::string ZombieEvent::randomChump()
{
	std::string name_pool[10] = {"Marin", "Medic", "Firebat", "Zealot", "Dragon", "Darktemplar", "Zergling", "Hydralisk", "Mutalisk", "Human"};
	std::string type;
	std::string res;

	res = name_pool[rand() % 10];
	if (res == "Marin" || res == "Medic" || res == "Firebat")
		this->setZombieType("Terran");
	else if (res == "Zealot" || res == "Dragon" || res == "Darktemplar")
		this->setZombieType("Protoss");
	else if (res == "Zergling" || res == "Hydralisk" || res == "Mutalisk")
		this->setZombieType("Zerg");
	else if (res == "Human")
		this->setZombieType("Human");
	return (res);
}