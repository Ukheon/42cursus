#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
{
	std::cout << "* click click click *" << std::endl;
	this->hp = 80;
	this->type = "RadScorpion";
}

RadScorpion::RadScorpion(const RadScorpion &type)
{
	std::cout << "* click click click *" << std::endl;
	*this = type;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

// std::string const &RadScorpion::getType() const
// {
// 	return (this->type);
// }

// int			RadScorpion::getHP() const
// {
// 	return (this->hp);
// }


RadScorpion &RadScorpion::operator=(RadScorpion const &type)
{
	if (this == &type)
		return (*this);
	this->hp = type.hp;
	this->type = type.type;
	return (*this);
}

void RadScorpion::takeDamage(int damage)
{
	this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}