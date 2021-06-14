#ifndef ZOMBIEEVNET_HPP
# define ZOMBIEEVNET_HPP
# include "Zombie.hpp"
class ZombieHorde {
	private:
		Zombie		**Unit;
		int			size;
		std::string type;
	public:
		Zombie	*newZombie(std::string name);
		void	setZombieType(std::string input);
		void	announce();
		ZombieHorde(int n);
		ZombieHorde() {}
		~ZombieHorde();
		std::string getZombieType();
		std::string randomChump();
};
#endif