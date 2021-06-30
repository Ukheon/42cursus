#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main(void)
{
	ClapTrap clap("Kadet");
	FragTrap *player = new FragTrap("Ukwon");
	srand(time(NULL));
	player->rangedAttack("monster");
	player->meleeAttack("monster");
	player->takeDamage(10);
	player->takeDamage(rand() % 30);
	player->beRepaired(20);
	player->vaulthunter_dot_exe("monster");
	player->takeDamage(50);
	player->vaulthunter_dot_exe("monster");
	player->vaulthunter_dot_exe("monster");
	player->vaulthunter_dot_exe("monster");
	player->vaulthunter_dot_exe("monster");
	player->beRepaired(20);
	player->vaulthunter_dot_exe("monster");
	player->beRepaired(20);
	player->vaulthunter_dot_exe("monster");
	std::cout << "-----------------------------------" << std::endl;
	ScavTrap *scv = new ScavTrap("Ari");
	scv->rangedAttack("baron");
	scv->meleeAttack("baron");
	scv->takeDamage(20);
	scv->takeDamage(10);
	scv->takeDamage(100);
	scv->takeDamage(2);
	scv->beRepaired(20);
	scv->challengeNewcomer();
	scv->challengeNewcomer();
	scv->challengeNewcomer();
	scv->beRepaired(100);
	scv->challengeNewcomer();
	scv->challengeNewcomer();
	scv->challengeNewcomer();
	std::cout << "-----------------------------------" << std::endl;
	NinjaTrap *naruto = new NinjaTrap("Naruto");
	naruto->rangedAttack("Sakura");
	naruto->meleeAttack("Sakura");
	naruto->takeDamage(20);
	naruto->takeDamage(10);
	naruto->takeDamage(100);
	naruto->takeDamage(2);
	naruto->beRepaired(20);
	naruto->ninjaShoebox(*naruto);
	naruto->ninjaShoebox(clap);
	naruto->ninjaShoebox(*player);
	naruto->ninjaShoebox(*scv);
	naruto->ninjaShoebox(*scv);
	naruto->ninjaShoebox(*scv);
	naruto->ninjaShoebox(*scv);
	naruto->ninjaShoebox(*scv);
	naruto->beRepaired(100);
	naruto->ninjaShoebox(*player);
	naruto->ninjaShoebox(*player);
	delete player;
	delete scv;
	delete naruto;
}