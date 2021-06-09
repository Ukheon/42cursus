#include "ZombieHorde.hpp"

Zombie	*ZombieHorde::newZombie(std::string name)
{
	Zombie *res;
	res = new Zombie(name, this->type);
	return (res);
}

std::string ZombieHorde::getZombieType()
{
	return (this->type);
}

void	ZombieHorde::setZombieType(std::string input)
{
	this->type = input;
}

std::string ZombieHorde::randomChump()
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

void			ZombieHorde::announce()
{
	int i = 0;
	while (i < this->size)
		this->Unit[i++]->announce();
}

ZombieHorde::ZombieHorde(int n)
{
	int i = 0;
	std::cout << "Create Unit" << std::endl;
	this->size = n;
	this->Unit = new Zombie*[n];
	while (i < n)
	{
		this->Unit[i] = this->newZombie(this->randomChump());
		i++;
	}
}