#include "cat.hpp"
#include "dog.hpp"

int main(void)
{
	const Animal* j = new Dog();
	std::cout << " =========================== " << std::endl;
	const Animal* i = new Cat();
	std::cout << " =========================== " << std::endl;
	Cat test;
	Cat test2(test);
	j->makeSound();
	i->makeSound();
	std::cout << "============= deep copy check ==============" << std::endl;

	delete j;
	delete i;
	std::cout << " ptr delete success ! " << std::endl;
	return (0);
}
