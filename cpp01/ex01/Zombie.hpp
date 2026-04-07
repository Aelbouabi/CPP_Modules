#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void announce();
        void set_name(std::string nm);
};

Zombie* zombieHorde( int N, std::string name );
