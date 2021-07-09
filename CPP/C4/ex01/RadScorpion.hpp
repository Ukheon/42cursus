#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include "Enemy.hpp"
class RadScorpion : public Enemy {
public:
	RadScorpion();
	RadScorpion(const RadScorpion &type);
	virtual ~RadScorpion();
	RadScorpion &operator=(RadScorpion const &);
	virtual void takeDamage(int);
};
#endif