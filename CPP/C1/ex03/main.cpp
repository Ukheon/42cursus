#include "ZombieHorde.hpp"

int			myupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

void		ZombieHorde::clear_Unit()
{
	int i = 3;
	std::cout << "Nuclear Launch detected" << std::endl;
	sleep(1);
	while (i > 0)
	{
		std::cout << i-- << std::endl;
		sleep(1);
	}
	i = 0;
	while (i < this->size)
		delete this->Unit[i++];
}

int			main(void)
{
	srand(time(NULL));
	ZombieHorde create_zombie(10);
	create_zombie.announce();
	create_zombie.clear_Unit();
	return (0);
}