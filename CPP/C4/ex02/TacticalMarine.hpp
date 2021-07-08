#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include "ISpaceMarine.hpp"
# include <iostream>
class TacticalMarine : public ISpaceMarine {
private:
public:
	TacticalMarine();
	~TacticalMarine();
	TacticalMarine(const TacticalMarine &type);
	TacticalMarine &operator=(const TacticalMarine &type);
	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};
#endif