#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "here" << std::endl;
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
	if (target.getName() == )
	this->_xp += 10;
}
AMateria &AMateria::operator=(const AMateria &type)
{
}
