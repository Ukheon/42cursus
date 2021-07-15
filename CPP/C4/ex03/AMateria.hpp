#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
protected:
	unsigned int _xp;
	std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	virtual ~AMateria();
	std::string const & getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	AMateria &operator=(const AMateria &type);
};

#endif
