#ifndef ITER_HPP
# define ITER_HPP
#include <fstream>
# include <iostream>

class practice {
private:
	int iarr[5];
public:
	practice() {
		int idx;
		idx = 0;
		for (int i = 5; i > 0; i--)
			iarr[idx++] = i;
	}
	~practice() {} ;
	practice(practice const &type)
	{
		*this = type;
	}
	practice &operator=(practice const &type)
	{
		for (int i = 0; i < 5; i++)
			this->iarr[i] = type.iarr[i];
		return (*this);
	}
	int getArr(int idx) const
	{
		return (this->iarr[idx]);
	}
};

std::ostream &operator<<(std::ostream &out, practice const &type);

template <typename T>
void iter(T *arr, int limit, void (*f)(T value))
{
	for (int i = 0; i < limit; i++)
	{
		(*f)(arr[i]);
	}
}

template <typename T>
void print(T value)
{
	std::cout << value << std::endl;
}

#endif
