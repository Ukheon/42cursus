#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>
class Enemy {
protected:
	Enemy();
	int			hp;
	std::string	type;
public:
	Enemy(const Enemy &type);
	virtual ~Enemy();
	Enemy &operator=(Enemy const &);
	std::string const &getType() const;
	int					getHP() const;
	virtual void takeDamage(int);
};
#endif