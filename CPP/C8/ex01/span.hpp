#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <set>

class Span {
private:
	Span() { }
	unsigned int size;
	std::set<int> arrV;
public:
	Span(unsigned int N);
	Span(const Span &type);
	~Span();
	Span &operator=(Span const &type);
	void addNumber(int value);
	template <typename T>
	void addNumber(T begin, T end)
	{
		try
		{
			for (; begin != end; ++begin)
			{
				if (this->size <= this->arrV.size())
					throw Span::overIdx();
				if (this->arrV.end() == std::find(this->arrV.begin(), this->arrV.end(), *begin))
					this->arrV.insert(*begin);
				else
					throw Span::existNumber();
			}
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	class existNumber : public std::exception {
		const char *what() const throw();
	};
	class overIdx : public std::exception {
		const char *what() const throw();
	};
	class sizeError : public std::exception {
		const char *what() const throw();
	};
	long longestSpan();
	long shortestSpan();
};
#endif
