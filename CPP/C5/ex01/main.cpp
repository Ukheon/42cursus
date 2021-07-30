#include "Bureaucrat.hpp"
#include "Form.hpp"
int	main(void)
{
	try
	{
		Form paper("Kadet", 100, 50);
		Bureaucrat person("Ukwon", 90);
		person.signForm(paper);
		paper.beSigned(person);
		std::cout << paper << std::endl;
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
