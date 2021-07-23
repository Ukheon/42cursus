#include "Bureaucrat.hpp"
#include "Form.hpp"
int	main(void)
{
	try
	{
		Form		check("ukwon", 100, 50);
		Bureaucrat person("ukwon", 50);
		std::cout << check.isSigned() << std::endl;
		check.beSigned(person);
		std::cout << person << std::endl;
		std::cout << check << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	//try
	//{
	//	Bureaucrat person("ukwon", 1);
	//	person.decrement();
	//	person.increment();
	//	person.decrement();
	//	std::cout << person << std::endl;
	//}
	//catch (std::exception & e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//try
	//{
	//	Bureaucrat person("ukwon", 150);
	//	person.increment();
	//	person.increment();
	//	person.decrement();
	//	std::cout << person << std::endl;
	//}
	//catch (std::exception & e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//try
	//{
	//	Bureaucrat person("ukwon", 150);
	//	person.increment();
	//	person.decrement();
	//	person.decrement();
	//	std::cout << person << std::endl;
	//}
	//catch (std::exception & e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//try
	//{
	//	Bureaucrat person("ukwon", 200);
	//	person.increment();
	//	person.decrement();
	//	person.decrement();
	//	std::cout << person << std::endl;
	//}
	//catch (std::exception & e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//try
	//{
	//	Bureaucrat person("ukwon", 0);
	//	person.increment();
	//	person.decrement();
	//	person.decrement();
	//	std::cout << person << std::endl;
	//}
	//catch (std::exception & e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//try
	//{
	//	Bureaucrat person("ukwon", 1);
	//	std::cout << person << std::endl;
	//	person.increment();
	//}
	//catch (std::exception & e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	return (0);
}
