#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
    if (ac == 2)
    {
        try
        {
            BitcoinExchange btc;
            btc.in_B(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    else
        std::cout << "ERROR: ./btc 'InputFile'" << std::endl;
    
}