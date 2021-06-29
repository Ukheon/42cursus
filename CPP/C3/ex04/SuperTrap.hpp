#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include "NinjaTrap.hpp"
class SuperTrap : public NinjaTrap, public FragTrap{
public:
	SuperTrap();
	~SuperTrap();
	SuperTrap(const std::string name);
	SuperTrap(const SuperTrap &Trap);
	SuperTrap		&operator = (const SuperTrap &Trap);
	void	        initPlayer();
	void			meleeAttack(std::string const & Trap);
	void			rangedAttack(std::string const & Trap);
};

#endif