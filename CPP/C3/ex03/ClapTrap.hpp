#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <time.h>
class ClapTrap {
protected:
	int hitPoint;
	int maxHitPoint;
	int energy;
	int maxEnergy;
	int level;
	int melle;
	int range;
	int armor;
	std::string name;
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &Trap);
	ClapTrap		&operator = (const ClapTrap &Trap);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};
#endif