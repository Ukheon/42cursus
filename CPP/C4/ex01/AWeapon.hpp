#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>
class AWeapon
{
protected:
	std::string name;
	int			damage;
	int			ap_cost;
	AWeapon();
public:
	AWeapon(const AWeapon &type);
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon();
	AWeapon &operator=(const AWeapon &type);

	std::string const &getName() const;	
	int			getAPCost() const;
	int			getDamage() const;
	virtual	void attack() const = 0;
};
#endif