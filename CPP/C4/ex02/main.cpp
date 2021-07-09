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

	temp->push(bob);
	temp->push(jim);
	vlc->push(bob);
	vlc->push(jim);
	vlc->push(tt);
	ISquad *copy = new Squad(*(Squad *)temp);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete copy;
	delete temp;
	std::cout << "here?\n";
	delete vlc;
	return 0;
}