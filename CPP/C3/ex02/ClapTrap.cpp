#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "unknwon";
	std::cout << "Parent class Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &Trap)
{
	*this = Trap;
}

ClapTrap::ClapTrap(const std::string name)
{
	this->name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "exit parent class" << std::endl;
}


ClapTrap		&ClapTrap::operator = (const ClapTrap &Trap)
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

void			ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount < this->armor)
		amount = 0;
	else
		amount -= this->armor;
	std::cout << "FR4G take " << amount << " points of damage!" << std::endl;
	this->hitPoint -= amount;
	if (this->hitPoint < 0)
		this->hitPoint = 0;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "FR4G is repaired for " << amount << "!" << std::endl;
	this->hitPoint += amount;
	this->energy += amount;
	if (this->hitPoint >= this->maxHitPoint)
		this->hitPoint = this->maxHitPoint;
	if (this->energy >= this->maxEnergy)
		this->energy = this->maxEnergy;
}