#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
class HumanA {
	private:
		Weapon			*Soard;
		std::string		name;
	public:
		HumanA();
		HumanA(std::string name, Weapon &str);
		void attack();
};
#endif
