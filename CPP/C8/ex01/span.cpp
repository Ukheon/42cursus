#include "span.hpp"

Span::Span(unsigned int N)
{
	this->size = N;
}

Span::Span(const Span &type)
{
	this->size = type.size;
	*this = type;
}

Span::~Span()
{
	;
}

const char *Span::existNumber::what() const throw()
{
	return ("exist Number");
}

const char *Span::overIdx::what() const throw()
{
	return ("over Idx");
}

const char *Span::sizeError::what() const throw()
{
	return ("size Error");
}

Span &Span::operator=(Span const &type)
{
	this->arrV.clear();
	for (std::set<int>::iterator p = type.arrV.begin(); p != type.arrV.end(); p++)
	{
		this->arrV.insert(*p);
	}
	return (*this);
}

void Span::addNumber(int value)
{
	std::set<int>::iterator p;
	p = this->arrV.end();
	try
	{
		if (this->size <= this->arrV.size())
			throw Span::overIdx();
		if (p == std::find(this->arrV.begin(), this->arrV.end(), value))
			this->arrV.insert(value);
		else
			throw Span::existNumber();
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

long Span::shortestSpan()
{
	if (this->arrV.size() <= 1)
		throw Span::sizeError();
	std::set<int>::iterator end = --this->arrV.end();
	long res = static_cast<long>(*(++this->arrV.begin())) - static_cast<long>(*(this->arrV.begin()));

	for (std::set<int>::iterator p = this->arrV.begin(); p != end; ++p)
	{
		if (res > *(++p) - *(--p))
			res = *(++p) - *(--p);
	}
	return (res);
}

long Span::longestSpan()
{
	if (this->arrV.size() <= 1)
		throw Span::sizeError();
	long res = static_cast<long>(*(--this->arrV.end()) - static_cast<long>(*(this->arrV.begin())));
	return (res);
}
