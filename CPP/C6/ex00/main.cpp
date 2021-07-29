#include "interpreter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: bad argument" << std::endl;
		return (0);
	}
	interpreter startProgram(argv[1]);
	//interpreter copy;
	//copy = startProgram;
	startProgram.print();
	//copy.print();
	return (0);
}
