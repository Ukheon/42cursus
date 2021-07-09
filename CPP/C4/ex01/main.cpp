#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "lightsaber.hpp"
#include "zombie.hpp"

int main()
{
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	Enemy* a = new zombie();
	Enemy* c = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	AWeapon* ls = new lightsaber();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	me->attack(a);
	me->attack(a);
	std::cout << *me;
	std::cout << "---------------------------------- new Weapon && Enemy Test" << std::endl;
	me->equip(ls);
	me->attack(a);
	me->attack(a);
	me->attack(a);
	me->attack(a);
	me->attack(a);
	me->attack(a);
	me->attack(a);
	me->attack(a);
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->equip(pr);
	std::cout << *me;
	me->attack(c);
	me->attack(c);
	me->attack(c);
	me->attack(c);
	me->attack(c);
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->attack(c);
	me->attack(c);
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
	me->equip(pf);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	delete me;
	delete pr;
	delete pf;
	delete ls;
	return 0;
}