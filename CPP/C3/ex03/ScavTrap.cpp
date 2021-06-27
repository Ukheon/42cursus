#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "unknwon";
	this->initPlayer();
}

ScavTrap::ScavTrap(const ScavTrap &Trap)
{
	*this = Trap;
}

ScavTrap::~ScavTrap()
{
	std::cout << "bye bye. bye.. bye... i remember you . . . . . . don`t forget me :d" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	this->name = name;
	this->initPlayer();
}

void		ScavTrap::initPlayer()
{
	std::cout << ":D ! Are you playing with me?!?!?!!!!" << std::endl;
	this->hitPoint = 100;
	this->maxHitPoint = 100;
	this->maxEnergy = 50;
	this->energy = 50;
	this->level = 1;
	this->melle = 20;
	this->range = 15;
	this->armor = 5;
}

void		ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "Scav <" << this->name << "> attacks <" << target << "> at range, wow. your attack <" << this->range << "> points of damage!" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "Scav <" << this->name << "> attacks <" << target << "> at melee, wow. your attack <" << this->melle << "> points of damage!" << std::endl;
}


ScavTrap		&ScavTrap::operator = (const ScavTrap &Trap)
{
	this->name = Trap.name;
	this->hitPoint = Trap.hitPoint;
	this->maxHitPoint = Trap.maxHitPoint;
	this->maxEnergy = Trap.maxEnergy;
	this->level = Trap.level;
	this->melle = Trap.melle;
	this->range = Trap.range;
	this->armor = Trap.armor;
	this->energy = Trap.energy;
	return (*this);
}

void		ScavTrap::challengeNewcomer()
{
	if (this->energy < 25)
	{
		std::cout << "not enough energy" << std::endl;
		return ;
	}
	this->energy -= 25;
	std::string arr[5] = {"Jayce", "Rammus", "Lulu", "Ezreal", "Lucian"};
	std::string skill;
	skill = arr[rand() % 5];
	if (skill == "Jayce")
		std::cout << "Jayce: I fight for a better future." << std::endl;
	else if (skill == "Rammus")
		std::cout << "Rammus: Ok." << std::endl;
	else if (skill == "Ezreal")
		std::cout << "Ezreal: You belong in a museum!!" << std::endl;
	else if (skill == "Lucian")
		std::cout << "Lucian: Everybody dies. Some just need a little help." << std::endl;
	else if (skill == "Lulu")
		std::cout << "Lulu: It's big!!, it's really big!!!!!!" << std::endl;
}