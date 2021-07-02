#include "Sorcerer.hpp"


int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	child sam("ukwon");

	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(sam);
	return 0;
}