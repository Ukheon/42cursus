#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
class Brain {
public:
	std::string *idea;
	Brain();
	virtual ~Brain();
	Brain(Brain const &type);
	Brain &operator=(Brain const &type);
};
#endif
