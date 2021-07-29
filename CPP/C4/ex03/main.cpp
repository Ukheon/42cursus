#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp = NULL;
	AMateria* temp = NULL;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	temp = tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(-1, *bob);
	std::cout << "materia exp: " << tmp->getXP() << std::endl;
	me->use(0, *bob);
	me->use(0, *bob);
	me->use(0, *bob);
	me->use(0, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(1, *bob);
	me->use(1, *bob);
	std::cout << "materia exp: " << temp->getXP() << std::endl;
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	std::cout << " ========= " << std::endl;
	me->unequip(0);
	me->use(2, *bob);
	me->unequip(0);
	me->use(2, *bob);
	std::cout << "materia exp: " << tmp->getXP() << std::endl;
	me->use(3, *bob);
	me->unequip(-1);
	delete bob;
	delete me;
	delete src;

	return (0);
}
