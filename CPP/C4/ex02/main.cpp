#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* tt = new AssaultTerminator;
	ISquad *vlc = new Squad;
	ISquad *temp = new Squad;


	vlc->push(bob);
	vlc->push(jim);
	vlc->push(tt);
	*(Squad *)temp = *(Squad *)vlc;
	vlc->push(tt);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	for (int i = 0; i < temp->getCount(); ++i)
	{
		ISpaceMarine* cur = temp->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	return 0;
}