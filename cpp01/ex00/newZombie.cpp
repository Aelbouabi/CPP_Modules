#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
    Zombie *ne = new Zombie(name);
    return (ne);
}
