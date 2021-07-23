#include "cat.hpp"
#include "dog.hpp"

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Cat test;
	Cat test2(test);
	const Animal* cuteDog = new Dog();
	const Animal* cuteCat = new Cat();
	cuteDog->makeSound();
	cuteCat->makeSound();
	std::cout << "============= deep copy check ==============" << std::endl;
	std::cout << &test.tmp << std::endl;
	std::cout << &test2.tmp << std::endl;
	delete j;
	delete i;
	delete cuteDog;
	delete cuteCat;
	return (0);
}
