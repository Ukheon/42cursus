#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
class Weapon {
	private:
		std::string 		Type;
	public:
		Weapon(std::string &str);
		Weapon();
		const std::string	&getType();
		void				setType(std::string type);
		Weapon(std::string club);
};
#endif
