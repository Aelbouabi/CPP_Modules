#include "Zombie.hpp"

int main()
{
    Zombie *ne = newZombie("foo");
    ne->announce();
    delete(ne);
    randomChump("avatar");
    return 0;
}
