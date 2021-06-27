#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <time.h>
class ScavTrap {
private:
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
	ScavTrap();
	~ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &Trap);
	ScavTrap		&operator = (const ScavTrap &Trap);
	void			initPlayer();
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
    void            challengeNewcomer();
};
#endif