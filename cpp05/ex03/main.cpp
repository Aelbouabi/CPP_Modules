#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main() {

    try
    {
        Bureaucrat mark("mark", 10);
        Intern someRandomIntern;
        AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form1 << std::endl;
        delete form1;
        AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        form2->execute(mark);
        std::cout << *form2 << std::endl;
        delete form2;
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Zoidberg");
        std::cout << *form3 << std::endl;
        delete form3;
        AForm* form4 = someRandomIntern.makeForm("unknown form", "Nobody");
        std::cout << *form4 << std::endl;
        delete form4;
    }
    catch(const std::exception& e) 
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
