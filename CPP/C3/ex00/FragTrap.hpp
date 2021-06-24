#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
class FragTrap {
private:
	int hit;
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
	FragTrap(const FragTrap &Trap);
	FragTrap		&operator = (const FragTrap &Trap);

	int				rangedAttack(std::string const & target);
	int				meleeAttack(std::string const & target);
	int				takeDamage(unsigned int amount);
	int				beRepaired(unsigned int amount);
};
#endif