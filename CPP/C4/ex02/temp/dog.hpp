#ifndef DOG_HPP
# define DOG_HPP
# include "animal.hpp"
# include "brain.hpp"
class Dog : public Animal{
private:
	Brain *tmp;
public:
	Dog();
	~Dog();
	Dog(Dog const &type);
	std::string getType() const;
	Dog &operator=(Dog const &type);
	void makeSound() const;
};
#endif
