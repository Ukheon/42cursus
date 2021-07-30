#include <iostream>
#include <stdint.h>
struct Data
{
	std::string s1;
	int	n;
	std::string s2;
};

uintptr_t serialize(Data *data)
{
	std::string source = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str[40];
	char *div;
	int len = source.length();
	int *integer = new int(rand() % 2102030405);
	div = reinterpret_cast<char *>(integer);
	for (int i = 0; i < 40; i++)
	{
		if (!(i >= 20 && i <= 23))
			str[i] = source[rand() % len];
		else
			str[i] = *(div++);
	}
	data->s1 = std::string(str, 20);
	data->s2 = std::string(str + 24, 16);
	uintptr_t res = reinterpret_cast<uintptr_t>(str);
	data->n = *reinterpret_cast<int *>(res + 20);
	std::cout << res << std::endl;
	std::cout << " =========== " << std::endl;
	return (res);
}

Data* deserialize(uintptr_t raw)
{
	Data *res = new Data;

	char *str = reinterpret_cast<char *>(raw);
	std::cout << raw << std::endl;

	res->s1 = std::string(reinterpret_cast<char *>(raw + 4), 20);
	res->n = *reinterpret_cast<int *>(raw + 20);
	res->s2 = std::string(reinterpret_cast<char *>(raw + 24), 16);
	std::cout << sizeof(res->s1) << std::endl;
	std::cout << &res->n << std::endl;
	std::cout << &res->s2 << std::endl;
	return (res);
}

int		main(void)
{
	Data *before = new Data;
	uintptr_t raw;
	raw = serialize(before);
	Data *after = deserialize(raw);
	std::cout << "before s1 : " << before->s1 << std::endl;
	std::cout << "before n : " << before->n << std::endl;
	std::cout << "before s1 : " << before->s2 << std::endl;
	std::cout << "after s1 : " << after->s1 << std::endl;
	std::cout << "after n : " << after->s1 << std::endl;
	std::cout << "after s2 : " << after->s2 << std::endl;

	return (0);
}
