#ifndef CAT_HPP
# define CAT_HPP
# include "animal.hpp"
class Cat : public Animal{
public:
	Cat();
	~Cat();
	Cat(Cat const &type);
	std::string getType() const;
	Cat &operator=(Cat const &type);
	void makeSound() const;
};
#endif
