#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat boo("boob", 1);
        std::cout << boo << std::endl;
        Form f("barqiya",0, 5, 20);
        std::cout << f << std::endl;
        boo.Dec_Grade();
        boo.Dec_Grade();
        boo.Dec_Grade();
        boo.Dec_Grade();
        boo.Dec_Grade();
        boo.Dec_Grade();
        std::cout << boo << std::endl;
        f.beSigned(boo);
        std::cout << f << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl; 
    }
    return 0;
}
