#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>
class AWeapon
{
protected:
	AWeapon();
public:
	AWeapon(std::string const & name, int apcost, int damage);
	~AWeapon();
	std::string getName() const;
	int getAPCost() const;
	int getDamage() const;
	void attack() const;
};
#endif