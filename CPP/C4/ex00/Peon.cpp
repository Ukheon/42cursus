#include "Peon.hpp"

Peon::Peon(std::string name)
:Victim(name)
{
	this->name = name;
	std::cout << "Zog zog" << std::endl;
}

Peon::Peon(const Peon &type)
{
	*this = type;
	
}

void	Peon::getPolymorphed() const
{
	std::cout << this->name + " has been turned into a pink pony" << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(const Peon &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	return (*this);
}

std::string Peon::callText() const
{
	std::string message = "I'm " + this->name + " and I like otters!";
	return (message);
}

std::ostream &operator << (std::ostream &out, const Peon &type)
{
	out << type.callText() << std::endl;
	return (out);
}


