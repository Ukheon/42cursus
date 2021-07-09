#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout <<"I’ll be back..." << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &type)
{
	
	*this = type;
}

AssaultTerminator &AssaultTerminator::operator=(const AssaultTerminator &type)
{
	if (this == &type)
		return (*this);
	return (*this);
}

ISpaceMarine* AssaultTerminator::clone() const
{
	ISpaceMarine *unit;

	unit = new AssaultTerminator(*this);
	return (unit);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;	
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}