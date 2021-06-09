#include "Human.hpp"

std::string		 Brain::identify()
{
	std::stringstream	itohex;
	std::string			res;
	std::string			temp;
	itohex << std::hex << (long long int)this;
	temp = myupper(itohex.str());
	res = "0x";
	res.append(temp);
	return (res);
}