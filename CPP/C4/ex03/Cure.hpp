#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Cure : public AMateria {
public:
	Cure();
	Cure(Cure const & type);
	virtual ~Cure();
	std::string const & getType() const;
	unsigned int getXP() const;
	Cure* clone() const;
	void use(ICharacter& target);
	Cure &operator=(const Cure &type);
};

#endif
