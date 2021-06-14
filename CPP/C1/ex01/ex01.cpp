#include <iostream>

void memoryLeak()
{
    std::string* panther = new std::string("String panther");
    std::cout << *panther << std::endl;
	delete panther;
}

int				main(void)
{
	memoryLeak();
	system("leaks a.out");
	return (0);
}