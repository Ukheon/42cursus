#include "brain.hpp"

Brain::Brain()
{
	this->idea = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		this->idea[i] = i;
	}
	std::cout << "Constructor Brain" << std::endl;
}

Brain::~Brain()
{
	delete[] this->idea;
	std::cout << "Destructors Brain" << std::endl;
}

Brain::Brain(Brain const &type)
{
	this->idea = new std::string[100];
	*this = type;
}

Brain &Brain::operator=(Brain const &type)
{
	for (int i = 0; i < 100; i++)
	{
		this->idea[i] = type.idea[i];
	}
	return (*this);
}
