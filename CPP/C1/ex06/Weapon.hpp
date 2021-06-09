#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
class Weapon {
	private:
		std::string 		Type;
	public:
		Weapon();
		const std::string	&getType();
		void				setType();
		Weapon(std::string club);
};
#endif