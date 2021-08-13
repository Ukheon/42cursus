#include "span.hpp"

//template <typename T>
//void Span::addNumber(T begin, T end)
//{
//	try
//	{
//		for (; begin != end; ++begin)
//		{
//			if (this->size <= this->arrV.size())
//				throw Span::overIdx();
//			if (this->arrV.end() == std::find(this->arrV.begin(), this->arrV.end(), *begin))
//				this->arrV.insert(*begin);
//			else
//				throw Span::existNumber();
//		}
//	}
//	catch (std::exception &e)
//	{
//		std::cout << "Error: " << e.what() << std::endl;
//	}
//}

void subjectTest()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void testIterator()
{
	Span sp = Span(10000);
	std::vector<int> fill;
	for (int i = 0; i < 10000; i++)
	{
		fill.push_back(i);
	}
	sp.addNumber(fill.begin(), fill.end());
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testError()
{
	Span sp(10);
	sp.addNumber(1);
	sp.addNumber(12);
	sp.addNumber(123);
	sp.addNumber(1234);
	sp.addNumber(12345);
	sp.addNumber(123456);
	sp.addNumber(1234567);
	sp.addNumber(12345678);
	sp.addNumber(123456789);
	sp.addNumber(1);
	sp.addNumber(10);
	sp.addNumber(1);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "========================" << std::endl;
	Span empty(10);
	try
	{
		std::cout << empty.shortestSpan() << std::endl;
		std::cout << empty.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main(void)
{
	subjectTest();
	std::cout << "========================" << std::endl;
	testIterator();
	std::cout << "========================" << std::endl;
	testError();

	return (0);
}
