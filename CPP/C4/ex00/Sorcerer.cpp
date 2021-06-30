#include "Sorcerer.hpp"
Sorcerer::Sorcerer(const std::string name, const std::string title)
{
	std::cout << name + ", " << title + ", is born!" << std::endl;
	this->name = name;
	this->title = title;
}
Sorcerer::Sorcerer(const Sorcerer &type)
{
	*this = type;
}

Sorcerer::~Sorcerer()
{
	
}

Sorcerer &Sorcerer::operator=(const Sorcerer &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	this->title = type.title;
	return (*this);
}