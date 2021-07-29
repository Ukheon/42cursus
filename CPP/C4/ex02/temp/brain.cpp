#include "brain.hpp"

Brain::Brain()
{
	this->idea = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			this->idea[i] == "Cat";
		else
			this->idea[i] == "Dog";
	}
	std::cout << "create Brain" << std::endl;
}

Brain::~Brain()
{
	delete[] this->idea;
	std::cout << "deideauctor Brain" << std::endl;
}

Brain::Brain(Brain const &type)
{
	;
}

Brain &Brain::operator=(Brain const &type)
{
	return (*this);
}
