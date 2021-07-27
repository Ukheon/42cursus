#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
class Animal {
protected:
	std::string type;
public:
	Animal();
	~Animal();
	Animal(Animal const &type);
	virtual std::string getType() const;
	Animal &operator=(Animal const &type);
	virtual void makeSound() const;
};
#endif