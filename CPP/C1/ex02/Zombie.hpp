#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <time.h>
# include <unistd.h>
class Zombie {
	private:
		std::string name;
		std::string type;
	public:
		Zombie(std::string name, std::string type);
		void announce(void);
		~Zombie();
};
#endif