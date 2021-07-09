#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include "Enemy.hpp"
class zombie : public Enemy {
public:
	zombie();
	zombie(const zombie &type);
	virtual ~zombie();
	zombie &operator=(zombie const &);
	virtual void takeDamage(int);
};
#endif