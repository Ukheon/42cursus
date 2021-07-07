#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"
class PlasmaRifle : public AWeapon {
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &type);
	~PlasmaRifle();
	PlasmaRifle &operator=(const PlasmaRifle &type);
	void attack() const;
};
#endif