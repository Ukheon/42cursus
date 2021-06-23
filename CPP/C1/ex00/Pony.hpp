#ifndef PONY_HPP
# include <iostream>
# define PONY_HPP
class Pony {
	public:
		Pony () {
			std::cout << "Class가 생성되었습니다!" << std::endl;
		}
		~Pony () {
			std::cout << "Class가 소멸되었습니다!" << std::endl;
		}
};

void ponyOnTheHeap();
void ponyOnTheStack();

#endif
