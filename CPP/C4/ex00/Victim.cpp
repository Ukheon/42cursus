#include "Victim.hpp"

Victim::Victim()
{
	;
}

Victim::Victim(std::string name)
{
	this->name = name;
	std::cout << "Some random victim called " + this->name + " just apperared!" << std::endl;
}

Victim::Victim(const Victim &type)
{
	*this = type;
}

Victim::~Victim()
{
	std::cout << "Victim " + this->name + " just died for no apparent reason!" << std::endl;
}

Victim &Victim::operator=(const Victim &type)
{
	if (this == &type)
		return (*this);
	this->name = type.name;
	return (*this);
}

std::string Victim::callText() const
{
	std::string message = "I'm " + this->name + " and I like otters!";
	return (message);
}

void	Victim::getPolymorphed() const
{
	std::cout << this->name + " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator << (std::ostream &out, const Victim &type)
{
	out << type.callText() << std::endl;
	return (out);
}