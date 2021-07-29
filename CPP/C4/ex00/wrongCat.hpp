#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal{
public:
	WrongCat();
	virtual ~WrongCat();
	WrongCat(WrongCat const &type);
	std::string getType() const;
	WrongCat &operator=(WrongCat const &type);
	void makeSound() const;
};
#endif
