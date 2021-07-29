#include "brain.hpp"

Brain::Brain()
{
	this->idea = new std::string[100];
	std::cout << "Constructor Brain" << std::endl;
}

Brain::~Brain()
{
	delete[] this->idea;
	std::cout << "Destructors Brain" << std::endl;
}

Brain::Brain(Brain const &type)
{
	;
}

Brain &Brain::operator=(Brain const &type)
{
	return (*this);
}
