#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "unknwon";
	this->hitPoint = 100;
	this->maxHitPoint = 100;
	this->maxEnergy = 100;
	this->level = 1;
	this->melle = 30;
	this->range = 20;
	this->armor = 5;
	std::cout << "Create Player" << std::endl;
}

FragTrap::FragTrap(const FragTrap &Trap)
{
	*this = Trap;
}

FragTrap::~FragTrap()
{
	std::cout << "\"" << this->name << "\" die. . ." << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "Create Player" << std::endl;
	this->hitPoint = 100;
	this->maxHitPoint = 100;
	this->maxEnergy = 100;
	this->level = 1;
	this->melle = 30;
	this->range = 20;
	this->armor = 5;
	this->name = name;
}

FragTrap		&FragTrap::operator = (const FragTrap &Trap)
{
	this->name = Trap.name;
	this->hitPoint = Trap.hitPoint;
	this->maxHitPoint = Trap.maxHitPoint;
	this->maxEnergy = Trap.maxEnergy;
	this->level = Trap.level;
	this->melle = Trap.melle;
	this->range = Trap.range;
	this->armor = Trap.armor;
	return (*this);
}

void			FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->name << "> attacks <" << target << "> at range, causing <" << this->range << "> points of damage!" << std::endl;
}

void			FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->name << "> attacks <" << target << "> at range, causing <" << this->melle << "> points of damage!" << std::endl;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	amount -= this->armor;
	this->hitPoint -= amount;
	if (this->hitPoint < 0)
		this->hitPoint = 0;
}

void			FragTrap::beRepaired(unsigned int amount)
{
	this->hitPoint += amount;
	if (this->hitPoint >= this->maxHitPoint)
		this->hitPoint = this->maxHitPoint;
}

// void			vaulthunter_dot_exe(std::string const & target)
// {

// }