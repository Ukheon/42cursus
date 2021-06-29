#include "NinjaTrap.hpp"
NinjaTrap::NinjaTrap()
{
	this->initPlayer();
	this->name = "unknwon";
}

NinjaTrap::NinjaTrap(const NinjaTrap &Trap)
{
	*this = Trap;
}

NinjaTrap::NinjaTrap(const std::string name)
{
	this->initPlayer();
	this->name = name;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "exit ninja class" << std::endl;
}

NinjaTrap		&NinjaTrap::operator = (const NinjaTrap &Trap)
{
	std::cout << "create ninja class" << std::endl;
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

void		NinjaTrap::initPlayer()
{
	std::cout << "create ninja class" << std::endl;
	this->hitPoint = 60;
	this->maxHitPoint = 60;
	this->maxEnergy = 120;
	this->energy = 120;
	this->level = 1;
	this->melle = 60;
	this->range = 5;
	this->armor = 0;
}

void			NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << this->name << ": attacks <" << target << "> at range, causing <" << this->range << "> points of damage!" << std::endl;
}

void			NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << this->name << ": attacks <" << target << "> at melee, causing <" << this->melle << "> points of damage!" << std::endl;
}

void			NinjaTrap::ninjaShoebox(FragTrap &type)
{
	std::string target = type.getName();
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

void		NinjaTrap::ninjaShoebox(ScavTrap &type)
{
	std::string target = type.getName();
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

void		NinjaTrap::ninjaShoebox(ClapTrap &type)
{
	if (this->energy < 25)
	{
		std::cout << "not enough energy" << std::endl;
		return ;
	}
	this->energy -= 25;
	std::string target = type.getName();
	std::cout << "i`m your parents. . . . " << target << " Nice to meet you . . ." <<std::endl;
}

void		NinjaTrap::ninjaShoebox(NinjaTrap &type)
{
	if (this->energy < 25)
	{
		std::cout << "not enough energy" << std::endl;
		return ;
	}
	this->energy -= 25;
	std::string target = type.getName();
	std::cout << target << " vs Sasuke who will win?" << std::endl;
}