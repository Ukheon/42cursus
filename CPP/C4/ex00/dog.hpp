#ifndef DOG_HPP
# define DOG_HPP
# include "animal.hpp"
class Dog : public Animal{
public:
	Dog();
	virtual ~Dog();
	Dog(Dog const &type);
	std::string getType() const;
	Dog &operator=(Dog const &type);
	void makeSound() const;
};
#endif
