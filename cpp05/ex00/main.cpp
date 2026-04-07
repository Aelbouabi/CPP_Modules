#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat boo("boob", 1);
        std::cout << boo << std::endl;
        boo.Inc_Grade();
        std::cout << boo << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << "_______________________________" << std::endl;
    try {
        Bureaucrat boo("snoop", 0);
        std::cout << boo << std::endl;
        boo.Inc_Grade();
        std::cout << boo << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << "_______________________________" << std::endl;
    try {
        Bureaucrat boo("klark", 50);
        std::cout << boo << std::endl;
        boo.Inc_Grade();
        std::cout << boo << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << "_______________________________" << std::endl;
     try {
        Bureaucrat boo("ben_dragon", 150);
        std::cout << boo << std::endl;
        boo.Dec_Grade();
        std::cout << boo << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << "_______________________________" << std::endl;
    try {
        Bureaucrat boo("loyd", 100);
        std::cout << boo << std::endl;
        boo.Dec_Grade();
        std::cout << boo << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << "_______________________________" << std::endl;
    try {
        Bureaucrat boo("solank", 151);
        std::cout << boo << std::endl;
        boo.Dec_Grade();
        std::cout << boo << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl; 
    }
    return 0;
}
