#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"
class AMateria;
class Character : public ICharacter{
private:
	AMateria	*slot[4];
	std::string name;
	int			limit;
public:
	Character();
	Character(std::string const name);
	Character(const Character &type);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	Character &operator=(const Character &type);
};

#endif
