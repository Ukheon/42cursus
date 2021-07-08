#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP
# include "ISpaceMarine.hpp"
# include <iostream>
class AssaultTerminator : public ISpaceMarine {
private:
public:
	AssaultTerminator();
	~AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &type);
	AssaultTerminator &operator=(const AssaultTerminator &type);
	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};
#endif