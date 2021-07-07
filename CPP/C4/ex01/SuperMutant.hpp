#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include "Enemy.hpp"
class SuperMutant : public Enemy {
public:
	SuperMutant();
	SuperMutant(const SuperMutant &type);
	virtual ~SuperMutant();
	SuperMutant &operator=(SuperMutant const &);
	// std::string const &getType() const;
	// int					getHP() const;
	virtual void takeDamage(int);
};
#endif