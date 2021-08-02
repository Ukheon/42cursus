#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat person("ukwon", 58);
		std::cout << person << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat person("ukwon", 1);
		person.decrement();
		std::cout << person << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat person("ukwon", 150);
		person.decrement();
		std::cout << person << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat person("ukwon", 0);
		std::cout << person << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat person("ukwon", 200);
		person.increment();
		person.decrement();
		person.decrement();
		std::cout << person << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
