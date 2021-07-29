#include <iostream>
#include <stdint.h>
uintptr_t how()
{
	unsigned int qq;
	qq = 123123123;
	unsigned int *test = &qq;
	char arr[40];
	for (int i = 0; i < 40; i++)
		arr[i] = i;
	uintptr_t a;
	std::string str = "str";
	std::string temp;
	a = reinterpret_cast<unsigned int>(qq);
	temp = std::string(static_cast<char *>(a));
	std::cout << a << std::endl;
	//std::cout << a << std::endl;
	return (a);
}

int		main(void)
{

	//	d->s1 = std::string(static_cast<char*>(raw), 8);
	//d->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	//d->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	std::string *temp;
	unsigned int gete;
	gete = how();
	char str = static_cast<char>(gete);
	temp = reinterpret_cast<std::string *>(str, 130);
	std::cout << str << std::endl;
	std::cout << temp << std::endl;
	//std::cout << *temp << std::endl;
	return (0);
}
