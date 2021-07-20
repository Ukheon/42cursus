#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
	this->_xp = 0;
}

Cure::Cure(Cure const & type)
{
	this->type = "cure";
	this->_xp = type._xp;
}

Cure::~Cure()
{
	;
}
std::string const & Cure::getType() const
{
	return (this->type);
}
unsigned int Cure::getXP() const
{
	return (this->_xp);
}
Cure* Cure::clone() const
{
	Cure *copy = new Cure(*this);
	copy->type = "cure";
	return (copy);
}
void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " + this->type + "`s wounds *" << std::endl;
}
Cure &Cure::operator=(const Cure &type)
{
	this->_xp = type._xp;
	this->type = type.type;
	return (*this);
}
