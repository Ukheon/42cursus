#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim {
protected:
	Victim();
	std::string name;
public:
	Victim(std::string name);
	Victim(const Victim &type);
	~Victim();
	Victim &operator=(const Victim &type);
	virtual void	getPolymorphed() const;
	std::string callText() const;
};
std::ostream		&operator << (std::ostream &out, const Victim &type);

#endif