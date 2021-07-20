#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}
AMateria::~AMateria()
{
	;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

unsigned int AMateria::getXP() const
{
	return (this->_xp);
}

void AMateria::use(ICharacter& target)
{
	this->_xp += 10;
}
AMateria &AMateria::operator=(const AMateria &type)
{
	return (*this);
}
