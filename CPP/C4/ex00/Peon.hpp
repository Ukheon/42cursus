#ifndef PEON_HPP
# define PEON_HPP
# include "Victim.hpp"

class Peon : public Victim {
private:
	Peon();
public:
	Peon(std::string name);
	Peon(const Peon &type);
	~Peon();
	Peon &operator=(const Peon &type);
	void	getPolymorphed() const;
	std::string callText() const;
};

std::ostream		&operator << (std::ostream &out, const Peon &type);

#endif