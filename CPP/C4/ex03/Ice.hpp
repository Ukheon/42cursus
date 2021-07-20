#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Ice : public AMateria {

public:
	Ice();
	Ice(Ice const &type);
	virtual ~Ice();
	std::string const & getType() const;
	unsigned int getXP() const;
	Ice* clone() const;
	void use(ICharacter& target);
	Ice &operator=(const Ice &type);
};

#endif
