#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
	this->initPlayer();
	this->name = "unknwon";
}

SuperTrap::SuperTrap(const SuperTrap &Trap)
{
	*this = Trap;
}

SuperTrap::SuperTrap(const std::string name)
{
	this->initPlayer();
	this->name = name;
}

SuperTrap::~SuperTrap()
{
	std::cout << "exit Super class" << std::endl;
}

void			SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}

void			SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

SuperTrap		&SuperTrap::operator = (const SuperTrap &Trap)
{
	std::cout << "create Super class" << std::endl;
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

void		SuperTrap::initPlayer()
{
	this->hitPoint = 100;
	this->maxHitPoint = 100;
	this->maxEnergy = 120;
	this->energy = 120;
	this->level = 1;
	this->melle = 60;
	this->range = 20;
	this->armor = 5;
}