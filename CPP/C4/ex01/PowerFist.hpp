#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
	PowerFist();
	PowerFist(const PowerFist &type);
	~PowerFist();
	PowerFist &operator=(const PowerFist &type);
	void attack() const;
};
#endif