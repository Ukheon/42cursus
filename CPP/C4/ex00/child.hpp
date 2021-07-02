#ifndef CHILD_HPP
# define CHILD_HPP
# include "Victim.hpp"

class child : public Victim {
private:
	child();
public:
	child(std::string name);
	child(const child &type);
	~child();
	child &operator=(const child &type);

	void	getPolymorphed() const;
};

#endif