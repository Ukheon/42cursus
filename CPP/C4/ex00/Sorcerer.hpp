#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
class Sorcerer {
private:
	std::string name;
	std::string title;
public:
	Sorcerer(std::string name, std::string title);
	~Sorcerer();
	Sorcerer(const Sorcerer &type);
	Sorcerer &operator=(const Sorcerer &type);
};
#endif