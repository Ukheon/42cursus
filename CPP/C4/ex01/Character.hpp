#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "Enemy.hpp"
# include "AWeapon.hpp"

class AWeapon;
class Enemy;

class Character {
private:
	int			ap;
	std::string name;
	AWeapon		*w_ptr;
public:
	Character();
	Character(std::string const & name);
	~Character();
	void	recoverAP();
	void	equip(AWeapon*);
	void	attack(Enemy*);
	int		getap() const;
	AWeapon	*check_type() const;
	// AWeapon getWeapon();
	std::string const &getName() const;
};

std::ostream 		&operator << (std::ostream &out, const Character &type);
#endif