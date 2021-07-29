#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::AMateria(AMateria const &type)
{
	(void)type;
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
	(void)target;
	this->_xp += 10;
}
AMateria &AMateria::operator=(const AMateria &type)
{
	this->type = type.type;
	this->_xp = type._xp;
	return (*this);
}
