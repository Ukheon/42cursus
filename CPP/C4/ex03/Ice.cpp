#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	this->_xp = 0;
}

Ice::Ice(Ice const & type)
{
	this->type = "ice";
	this->_xp = type._xp;
}

Ice::~Ice()
{
	;
}

std::string const & Ice::getType() const
{
	return (this->type);
}

unsigned int Ice::getXP() const
{
	return (this->_xp);
}

Ice* Ice::clone() const
{
	Ice *copy = new Ice(*this);
	copy->type = "ice";
	return (copy);
}

void Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << this->type + " *" << std::endl;
}

Ice &Ice::operator=(const Ice &type)
{
	this->_xp = type._xp;
	this->type = type.type;
	return (*this);
}
