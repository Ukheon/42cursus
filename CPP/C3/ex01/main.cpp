#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FragTrap *player = new FragTrap("ukwon");
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
    delete player;
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
    delete scv;
}