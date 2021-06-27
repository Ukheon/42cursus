#include "FragTrap.hpp"

int main(void)
{
    FragTrap player("ukwon");
    FragTrap player2;
    srand(time(NULL));
    player.rangedAttack("monster");
    player.meleeAttack("monster");
    player.takeDamage(10);
    player.takeDamage(rand() % 30);
    player.beRepaired(20);
    player.vaulthunter_dot_exe("monster");
    player.takeDamage(50);
    player.takeDamage(3);
    player.vaulthunter_dot_exe("monster");
    player.vaulthunter_dot_exe("monster");
    player.vaulthunter_dot_exe("monster");
    player.vaulthunter_dot_exe("monster");
    player.beRepaired(20);
    player.vaulthunter_dot_exe("monster");
    player.beRepaired(20);
    player.vaulthunter_dot_exe("monster");
    player2.vaulthunter_dot_exe(". . .");
    player2.vaulthunter_dot_exe(". . .");
    player2.vaulthunter_dot_exe(". . .");
    player2.vaulthunter_dot_exe(". . .");
    player2.vaulthunter_dot_exe(". . .");
}