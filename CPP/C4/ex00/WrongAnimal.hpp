#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(WrongAnimal const &type);
	virtual std::string getType() const;
	WrongAnimal &operator=(WrongAnimal const &type);
	void makeSound() const;
};
#endif
