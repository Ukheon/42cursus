#include "Pony.hpp"

void ponyOnTheHeap()
{
	std::cout << "Heap에 할당하겠습니다." << std::endl;
	Pony *hi;
	hi = new Pony[5];

	delete[] hi;
	std::cout << "Heap에 할당된 Class가 모두 소멸되었습니다!" << std::endl;
}

void ponyOnTheStack()
{
	std::cout << "Stack에 할당하겠습니다." << std::endl;
	Pony hi[5];
}

int				main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	std::cout << "Stack에 할당된 class가 모두 소멸되었습니다!" << std::endl;
	system("leaks a.out");
	return (0);
}