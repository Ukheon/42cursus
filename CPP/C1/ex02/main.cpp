#include "ZombieEvent.hpp"

int			main(void)
{
	Zombie		*Unit[5];
	ZombieEvent create_zombie;
	//Zombie		zom(create_zombie.randomChump(), create_zombie.getZombieType());
	int i = 0;
	srand(time(NULL));
	std::cout << "Create Unit" << std::endl;
	while (i < 5)
	{
		Unit[i] = create_zombie.newZombie(create_zombie.randomChump());
		i++;
	}
	i = 0;
	std::cout << "Nuclear Launch detected" << std::endl;
	i = 3;
	while (i > 0)
	{
		std::cout << i-- << std::endl;
		sleep(1);
	}
	i = 0;
	while (i < 5)
		delete Unit[i++];
	i = 0;
	return (0);
}