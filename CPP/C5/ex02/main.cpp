#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int	main(void)
{
	srand(time(NULL));
	Form *tree = new ShrubberyCreationForm("tree");
	Form *robot = new RobotomyRequestForm("Robot");
	Form *president = new PresidentialPardonForm("honor");
	try
	{
		Bureaucrat person("person", 123);
		std::cout << "==========================" << std::endl;
		std::cout << person << std::endl;
		person.signForm(*tree);
		person.excuteForm(*tree);
		std::cout << *tree << std::endl;
		std::cout << "==========================" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "==========================" << std::endl;
	}
	try
	{
		Bureaucrat person("person", 45);
		std::cout << "==========================" << std::endl;
		std::cout << person << std::endl;
		robot->beSigned(person);
		std::cout << *robot << std::endl;
		robot->execute(person);
		robot->execute(person);
		robot->execute(person);
		robot->beSigned(person);
		std::cout << *robot << std::endl;
		std::cout << "==========================" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "==========================" << std::endl;
	}
	try
	{
		Bureaucrat person("SuperPerson", 4);
		std::cout << "==========================" << std::endl;
		std::cout << person << std::endl;
		president->beSigned(person);
		std::cout << *president << std::endl;
		president->execute(person);
		std::cout << "==========================" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "==========================" << std::endl;
	}
	delete tree;
	delete robot;
	delete president;
	return (0);
}
