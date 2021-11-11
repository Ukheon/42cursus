#include "Human.hpp"

std::string		 Human::identify()
{
	std::cout << "first here" << std::endl;
	std::stringstream	itohex;
	std::string			res;
	std::string			temp;
	itohex << std::hex << (long long int)&this->brain;
	temp = myupper(itohex.str());
	res = "0x";
	res.append(temp);
	return (res);
}

Brain &Human::getBrain()
{
	return (this->brain);
}
