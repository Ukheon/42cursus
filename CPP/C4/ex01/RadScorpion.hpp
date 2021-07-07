#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include "Enemy.hpp"
class RadScorpion : public Enemy {
public:
	RadScorpion();
	RadScorpion(const RadScorpion &type);
	virtual ~RadScorpion();
	RadScorpion &operator=(RadScorpion const &);
	// std::string const &getType() const;
	// int					getHP() const;
	virtual void takeDamage(int);
};
#endif