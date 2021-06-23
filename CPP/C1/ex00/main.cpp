#include "Pony.hpp"

int				main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	std::cout << "Stack에 할당된 class가 모두 소멸되었습니다!" << std::endl;
	// system("leaks a.out");
	return (0);
}