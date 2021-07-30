//#include "Bureaucrat.hpp"
//#include "Form.hpp"
//#include "ShrubberyCreationForm.hpp"
//#include "RobotomyRequestForm.hpp"
//#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int	main(void)
{
	srand(time(NULL));
	Intern newbie;
	Form *test;
	try
	{
		test = newbie.makeForm("ShrubberyCreation", "wow");
		Bureaucrat person("person", 130);
		test->beSigned(person);
		test->execute(person);
		person.signForm(*test);
		person.excuteForm(*test);
		std::cout << *test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test;
	std::cout << "====================================================" << std::endl;
	try
	{
		test = newbie.makeForm("RobotomyRequest", "Optimus");
		Bureaucrat person("person", 30);
		test->beSigned(person);
		person.excuteForm(*test);
		test->execute(person);
		test->execute(person);
		std::cout << *test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test;
	std::cout << "====================================================" << std::endl;
	try
	{
		test = newbie.makeForm("RobotomyRequest", "Optimus");
		Bureaucrat person("person", 30);
		test->execute(person);
		std::cout << *test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test;
	std::cout << "====================================================" << std::endl;
	try
	{
		test = newbie.makeForm("PresidentialPardon", "President");
		Bureaucrat person("person", 28);
		std:: cout << *test << std::endl;
		person.excuteForm(*test);
		test->beSigned(person);
		test->execute(person);
		std::cout << *test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test;
	std::cout << "====================================================" << std::endl;
	try
	{
		test = newbie.makeForm("PresidentialPardon", "President");
		Bureaucrat person("person", 3);
		std:: cout << *test << std::endl;
		person.signForm(*test);
		person.excuteForm(*test);
		test->execute(person);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test;
	return (0);
}
