#include "dog.hpp"
#include "cat.hpp"
#include "wrongCat.hpp"
int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *bonus = new WrongCat();
	const WrongAnimal *no = new WrongAnimal();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	bonus->makeSound();
	no->makeSound();
	std::cout << bonus->getType() << " " << std::endl;
	delete meta;
	delete j;
	delete i;
	delete bonus;
	delete no;
	return (0);
}
