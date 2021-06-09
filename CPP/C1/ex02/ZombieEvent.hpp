#ifndef ZOMBIEEVNET_HPP
# define ZOMBIEEVNET_HPP
# include "Zombie.hpp"
class ZombieEvent {
	private:
		std::string type;
	public:
		Zombie	*newZombie(std::string name);
		void	setZombieType(std::string type);
		std::string getZombieType();
		std::string randomChump();
};
#endif