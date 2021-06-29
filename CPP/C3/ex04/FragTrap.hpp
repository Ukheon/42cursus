#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
class FragTrap : virtual public ClapTrap{
private:
public:
	FragTrap();
	~FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &Trap);
	FragTrap		&operator = (const FragTrap &Trap);
	void			vaulthunter_dot_exe(std::string const & target);
	void			initPlayer();
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
};
#endif
