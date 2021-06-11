#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void	case1()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}

void	case2()
{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}

int main()
{
	case1();
	case2();
	return (0);
}
