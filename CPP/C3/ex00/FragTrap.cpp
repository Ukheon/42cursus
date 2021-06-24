#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	;
}

FragTrap::FragTrap(const FragTrap &Trap)
{
	*this = Trap;
}

FragTrap::FragTrap()
{
	;
}

FragTrap		&FragTrap::operator = (const FragTrap &Trap)
{
	this->hit = Trap.hit;
	return (*this);
}