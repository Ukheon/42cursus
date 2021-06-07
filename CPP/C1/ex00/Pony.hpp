#ifndef PONY_HPP
# include <iostream>
# define PONY_HPP
class Pony {
	private:
		int index;
	public:
		Pony () {
			std::cout << "Class가 생성되었습니다!" << std::endl;
		}
		~Pony () {
			std::cout << "Class가 소멸되었습니다!" << std::endl;
		}
		void	insert_index(int input);
		int		get_index();
};
#endif
