#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);

        ShrubberyCreationForm shrubbery("shar");
        RobotomyRequestForm robotomy("robot");
        PresidentialPardonForm pardon("robot");

        alice.signForm(shrubbery);
        alice.signForm(robotomy);
        alice.signForm(pardon);

        alice.executeForm(shrubbery);
        alice.executeForm(robotomy);
        alice.executeForm(pardon);
    }
    catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
