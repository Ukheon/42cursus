#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
class HumanA {
	private:
		const Weapon	&Soard;
		std::string		name;
	public:
		HumanA();
		HumanA(std::string const &name, const Weapon &weapon);
		void attack();
};
#endif
