#include "RPN.hpp"

int main(int ac , char **av)
{
    if (ac != 2) {
        std::cout << "ERROR: ./RPN 'inverted Polish mathematical expression'" << std::endl;
        return 1;
    }
    try
    {
        std::string str = av[1];
        RPN arg(str);
        arg.Reverse_Polish();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}