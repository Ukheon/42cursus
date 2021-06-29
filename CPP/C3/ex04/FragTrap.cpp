#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "unknwon";
	this->initPlayer();
}

FragTrap::FragTrap(const FragTrap &Trap)
{
	*this = Trap;
}

FragTrap::~FragTrap()
{
	std::cout << "\"" << this->name << "\" exit this game." << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	this->name = name;
	this->initPlayer();
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
	this->energy = Trap.energy;
	return (*this);
}

void			FragTrap::initPlayer()
{
	std::cout << "Create Player " << this->name << std::endl;
	this->hitPoint = 100;
	this->maxHitPoint = 100;
	this->maxEnergy = 100;
	this->energy = 100;
	this->level = 1;
	this->melle = 30;
	this->range = 20;
	this->armor = 5;
}

void			FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->name << "> attacks <" << target << "> at range, causing <" << this->range << "> points of damage!" << std::endl;
}

void			FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->name << "> attacks <" << target << "> at range, causing <" << this->melle << "> points of damage!" << std::endl;
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->energy < 25)
	{
		std::cout << "not enough energy" << std::endl;
		return ;
	}
	this->energy -= 25;
	std::string arr[5] = {"icebolt", "firebolt", "earthquake", "meteor", "blizzard"};
	std::string skill;
	skill = arr[rand() % 5];
	if (skill == "icebolt")
		std::cout << "FR4G-TP <" << this->name << "> use icebolt! for " << target << " 7 points of damage!" << std::endl;
	else if (skill == "firebolt")
		std::cout << "FR4G-TP <" << this->name << "> use firebolt! for " << target << " 6 points of damage!" << std::endl;
	else if (skill == "earthquake")
		std::cout << "FR4G-TP <" << this->name << "> use earthquake! for " << target << " 27 points of damage!" << std::endl;
	else if (skill == "meteor")
		std::cout << "FR4G-TP <" << this->name << "> use meteor! for " << target << " 57 points of damage!" << std::endl;
	else if (skill == "blizzard")
		std::cout << "FR4G-TP <" << this->name << "> use blizzard! for " << target << " 77 points of damage!" << std::endl;
}