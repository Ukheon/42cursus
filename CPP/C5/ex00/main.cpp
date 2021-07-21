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
		std::cout << "Exception: wrong grade ! ! ! " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat person("ukwon", 1);
		person.decrement();
		person.increment();
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
		person.increment();
		person.increment();
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
		person.increment();
		person.decrement();
		person.decrement();
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
	try
	{
		Bureaucrat person("ukwon", 0);
		person.increment();
		person.decrement();
		person.decrement();
		std::cout << person << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat person("ukwon", 1);
		std::cout << person << std::endl;
		person.increment();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
