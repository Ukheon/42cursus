#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
class HumanA {
	private:
		Weapon			Soard;
		std::string		name;
	public:
		HumanA(std::string name, std::string input);
		void attack();
};
#endif