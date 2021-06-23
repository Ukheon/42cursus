#include "Pony.hpp"

void ponyOnTheHeap()
{
	std::cout << "Heap에 할당하겠습니다." << std::endl;
	Pony *hi;
	hi = new Pony;

	delete hi;
	std::cout << "Heap에 할당된 Class가 모두 소멸되었습니다!" << std::endl;
}

void ponyOnTheStack()
{
	std::cout << "Stack에 할당하겠습니다." << std::endl;
	Pony hi[1];
}