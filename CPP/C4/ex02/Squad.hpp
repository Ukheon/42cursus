#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"
# include <iostream>
class Squad : public ISquad {
private:
	int count;
	ISpaceMarine **units;
public:
	Squad();
	~Squad();
	Squad(const Squad &type);
	Squad &operator=(const Squad &type);
	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);
};
#endif