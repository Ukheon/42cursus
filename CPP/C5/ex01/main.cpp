#include "Bureaucrat.hpp"
#include "Form.hpp"
int	main(void)
{
		Bureaucrat *person = new Bureaucrat("ukwon", 110);
		std::cout << person->getName() << std::endl;
		Form		*check = new Form("Kadet", 100, 50);
		Bureaucrat test("qqqq", 110);
		std::cout << person->getName() << std::endl;
		std::cout << check->getName() << std::endl;
		std::cout << check->getName() << std::endl;
	//	std::cout << "===============" << std::endl;
	//	std::cout << person->getName() << std::endl;
	//	std::cout << check->getName() << std::endl;
	//	std::cout << "===============" << std::endl;

	//	person->signForm(*check);
	//	std::cout << *check << std::endl;
	//}
	//catch (std::exception & e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
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
