#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include "Peon.hpp"
# include "Victim.hpp"
# include "child.hpp"

class Sorcerer {
private:
	Sorcerer();

	std::string name;
	std::string title;
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer &type);
	~Sorcerer();
	Sorcerer &operator=(const Sorcerer &type);
	std::string	callText() const;
	void polymorph(Victim const &) const;
};

std::ostream		&operator << (std::ostream &out, const Sorcerer &type);

#endif