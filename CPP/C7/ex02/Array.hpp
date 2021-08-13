#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>
template <typename T>
class Array {
private:
	unsigned int n;
	T *tarr;
public:
	Array():n(0), tarr(NULL)
	{}
	Array(unsigned int n)
	{
		this->n = n;
		if (n > 0)
			this->tarr = new T[n];
		for (unsigned int i = 0; i < n; i++)
			this->tarr[i] = T();
	}
	Array(Array const &type)
	{
		this->n = type.n;
		this->tarr = new T[n];
		for (unsigned int i = 0; i < n; i++)
			this->tarr[i] = type.tarr[i];
	}
	~Array()
	{
		if (this->n > 0)
			delete[] this->tarr;
	}
	Array &operator=(Array const &type)
	{
		delete[] this->tarr;
		this->n = type.n;
		this->tarr = new T[this->n];
		for (unsigned int i = 0; i < n; i++)
			this->tarr[i] = type.tarr[i];
		return (*this);
	}
	unsigned int size() const
	{
		return (n);
	}
	class idxError : public std::exception {
		const char *what() const throw()
		{
			return ("ArrayIdxError: Not valid index");
		}
	};
	T &operator[](unsigned idx)
	{
		if (idx >= this->n || idx < 0)
			throw Array::idxError();
		return (this->tarr[idx]);
	}
};
#endif
