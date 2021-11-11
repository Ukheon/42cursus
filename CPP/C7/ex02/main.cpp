#include "Array.hpp"
#include <exception>
#include <typeinfo>



int main(void)
{
	Array<int> intR;
	Array<int> intRR(5);
	intR = intRR;
	for (unsigned int i = 0; i < intR.size(); i++)
	{
		intR[i] = i;

		//intR[i]  == arr int*
		//std::cout  << std::endl;
		std::cout << intR[i] << " ";
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < intRR.size(); i++)
	{
		std::cout << intRR[i] << " ";
	}
	std::cout << std::endl;

	Array<float> floatR(10);
	for (unsigned int i = 0; i < floatR.size(); i++)
	{
		std::cout << floatR[i] << "f ";
	}
	std::cout << std::endl;

	Array<unsigned int> uintR(5);
	for (unsigned int i = 0; i < uintR.size(); i++)
	{
		uintR[i] = i;
		std::cout << uintR[i] << " ";
	}
	std::cout << std::endl;

	Array<std::string> stringR(5);
	for (unsigned int i = 0; i < stringR.size(); i++)
		stringR[i] = "hi";
	try
	{
		for (unsigned int i = 0; i < stringR.size() + 1; i++)
			std::cout << uintR[i] << ": " << stringR[i] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << " ======================= " << std::endl;
	try
	{
		intR[10];
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		intRR[5] = 2;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
