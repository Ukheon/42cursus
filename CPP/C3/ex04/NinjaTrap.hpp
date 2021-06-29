#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
class NinjaTrap : virtual public ClapTrap {

public:
    NinjaTrap();
	~NinjaTrap();
	NinjaTrap(const std::string name);
	NinjaTrap(const NinjaTrap &Trap);
	NinjaTrap		&operator = (const NinjaTrap &Trap);
    void	        initPlayer();
    void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
    void            ninjaShoebox(NinjaTrap &type);
	void            ninjaShoebox(ClapTrap &type);
	void            ninjaShoebox(ScavTrap &type);
	void            ninjaShoebox(FragTrap &type);
};
#endif