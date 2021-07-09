#ifndef LIGHTSABER_HPP
# define LIGHTSABER_HPP
# include "AWeapon.hpp"
class lightsaber : public AWeapon{
public:
	lightsaber();
	lightsaber(const lightsaber &);
	~lightsaber();
	lightsaber &operator=(const lightsaber &);
	void attack() const;
};
#endif