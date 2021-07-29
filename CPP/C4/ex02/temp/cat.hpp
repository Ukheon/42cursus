#ifndef CAT_HPP
# define CAT_HPP
# include "animal.hpp"
# include "brain.hpp"
class Cat : public Animal{
private:
public:
	Brain *tmp;
	Cat();
	~Cat();
	Cat(Cat const &type);
	std::string getType() const;
	Cat &operator=(Cat const &type);
	void makeSound() const;
};
#endif
