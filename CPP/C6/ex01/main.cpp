#include <iostream>

struct Data
{
	std::string s1;
	int	n;
	std::string s2;
};

uintptr_t serialize(Data *d)
{
	std::string source = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *str, *div;
	int *integer = new int();
	str = new char[40];
	int len = source.length();
	*integer = rand() % 2102030405;
	div = reinterpret_cast<char *>(integer);
	for (int i = 0; i < 40; i++)
	{
		if (!(i >= 20 && i <= 23))
			str[i] = source[rand() % len];
		else
			str[i] = *(div++);
	}
	uintptr_t res = reinterpret_cast<uintptr_t>(str);
	d->s1 = std::string(str, 20);
	d->n = *integer;
	d->s2 = std::string(str + 24, 16);
	delete integer;
	return (res);
}

Data* deserialize(uintptr_t raw)
{
	Data *after = new Data;
	after->s1 = std::string(reinterpret_cast<char *>(raw), 20);
	after->n = *reinterpret_cast<int *>(raw + 20);
	after->s2 = std::string(reinterpret_cast<char *>(raw + 24), 16);
	char *del = reinterpret_cast<char *>(raw);
	delete del;
	return (after);
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
	std::cout << "after n : " << after->n << std::endl;
	std::cout << "after s2 : " << after->s2 << std::endl;
	delete before;
	delete after;
	return (0);
}
