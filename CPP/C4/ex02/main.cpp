#include "cat.hpp"
#include "dog.hpp"

int main(void)
{
	// 컴파일 오류 체크
	//Animal *t;
	//t = new Animal();
	const Animal* j = new Dog();
	std::cout << " =========================== " << std::endl;
	const Animal* i = new Cat();
	std::cout << " =========================== " << std::endl;
	Cat test;
	Cat test2(test);
	j->makeSound();
	i->makeSound();
	std::cout << "============= deep copy check ==============" << std::endl;
	std::cout << &test.tmp << std::endl;
	std::cout << &test2.tmp << std::endl;
	delete j;
	delete i;
	std::cout << " ptr delete success ! " << std::endl;
	return (0);
}
