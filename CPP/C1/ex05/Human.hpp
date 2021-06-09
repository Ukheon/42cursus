#ifndef HUMAN_HPP
# define HUMAN_HPP
# include <iostream>
# include <iomanip>
# include <sstream>
# include "Brain.hpp"

std::string			myupper(std::string str);
class Human {
	private:
		Brain brain;
	public:
		Brain &getBrain();
		std::string identify();
};
#endif