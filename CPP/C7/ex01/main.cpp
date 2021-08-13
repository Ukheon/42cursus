#include "iter.hpp"

std::ostream &operator<<(std::ostream &out, practice const &type)
{
	for (int i = 0; i < 5; i++)
		std::cout << type.getArr(i) << " ";
	std::cout << std::endl;
	out << "template class . . .";
	return (out);
}

int main()
{
	int iarr[5] = {1, 3, 5, 7, 9};
	iter(iarr, 5, print);

	double darr[5] = {1.0, 2.2, 3.3, 4.4, 5.5};
	iter(darr, 5, print);

	std::string str[5] = {"hi","nice","to","meet","you"};
	iter(str, 5, print);

	practice *test = new practice[3];
	iter(test, 3, print);
	delete[] test;
	return (0);
}
