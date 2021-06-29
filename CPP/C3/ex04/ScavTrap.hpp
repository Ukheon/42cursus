#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
class ScavTrap : public ClapTrap{
private:
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &Trap);
	ScavTrap		&operator = (const ScavTrap &Trap);
    void            challengeNewcomer();
	void			initPlayer();
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
};
#endif