#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
class Animal {
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal(Animal const &type);
	virtual std::string getType() const;
	Animal &operator=(Animal const &type);
	void makeSound() const;
};
#endif
