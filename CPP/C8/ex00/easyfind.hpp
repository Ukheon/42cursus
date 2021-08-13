#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <exception>
# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>
# include <map>

class findError : public std::exception
{
public:
	const char *what() const throw()
	{
		return ("empty template");
	}
};

template<typename T>
typename T::iterator easyfind(T &type, int value)
{
	try
	{
		if (type.begin() == type.end())
			throw findError();
		return (std::find(type.begin(), type.end(), value));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (type.end());
}

template<typename T, typename I>
typename std::map<T,I>::iterator easyfind(std::map<T, I> &type, int value)
{
	typename std::map<T, I>::iterator p;
	try
	{
		if (type.begin() == type.end())
			throw findError();
		for (p = type.begin(); p != type.end(); ++p)
		{
			if (p->second == value)
				return p;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (type.end());
}
#endif
