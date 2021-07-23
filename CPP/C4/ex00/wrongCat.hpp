#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal{
public:
	WrongCat();
	~WrongCat();
	WrongCat(WrongCat const &type);
	std::string getType() const;
	WrongCat &operator=(WrongCat const &type);
	void makeSound() const;
};
#endif
