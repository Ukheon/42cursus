#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <time.h>
class FragTrap {
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
	FragTrap();
	~FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &Trap);
	FragTrap		&operator = (const FragTrap &Trap);
	void			initPlayer();
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			vaulthunter_dot_exe(std::string const & target);
};
#endif