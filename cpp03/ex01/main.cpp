#include "ScavTrap.hpp"

int main( void ) {
    ClapTrap tomy("tomy");
    ScavTrap blad("blad");
    tomy.attack("hmaida");
    tomy.takeDamage(5);
    tomy.beRepaired(10);
    tomy.takeDamage(15);
    tomy.beRepaired(10);
    tomy.attack("hmaida");
    tomy.takeDamage(1);
    blad.attack("hmaida");
}