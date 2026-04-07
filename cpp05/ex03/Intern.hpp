#pragma once
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern &operator=(const Intern &src);
        Intern(const Intern &copy);
        ~Intern();
        AForm *makeForm(std::string form_name, std::string target);
        class InternExc : public std::exception {
            public:
                const char* what() const throw();
        };

};

