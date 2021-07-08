#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &type)
{
	*this = type;
}

TacticalMarine &TacticalMarine::operator=(const TacticalMarine &type)
{
	if (this == &type)
		return (*this);
	return (*this);
}

ISpaceMarine* TacticalMarine::clone() const
{
	ISpaceMarine *unit;

	unit = new TacticalMarine(*this);
	return (unit);
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;	
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}