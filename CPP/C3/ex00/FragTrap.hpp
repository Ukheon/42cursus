#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
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
	// Max hit points (100)
	// Energy points (100)
	// Max energy points (100)
	// Level (1)
	// Name (Parameter of constructor)
	// Melee attack damage (30)
	// Ranged attack damage (20)
	// Armor damage reduction (5)
public:
	FragTrap();
	~FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &Trap);
	FragTrap		&operator = (const FragTrap &Trap);

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			vaulthunter_dot_exe(std::string const & target);
};
#endif