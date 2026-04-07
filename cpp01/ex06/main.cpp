#include "Harl.hpp"

int main (int ac, char **av)
{
    if (ac == 2)
    {
        Harl p;
        p.complain(av[1]);
    }
    else
        std::cerr << "need just one parameter" << std::endl;
}