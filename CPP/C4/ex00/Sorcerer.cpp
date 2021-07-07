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
	std::cout << this->name + ", " << this->title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	this->title = type.title;
	return (*this);
}

std::ostream		&operator << (std::ostream &out, const Sorcerer &type)
{
	out << type.callText() << std::endl;
	return (out);
}

void				Sorcerer::polymorph(Victim const &type) const
{
	type.getPolymorphed();
}

std::string			Sorcerer::callText() const
{
	std::string message = "I am" + this->name + ", " + this->title + ", and I like ponies!";
	return (message);
}