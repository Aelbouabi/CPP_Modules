#pragma once
#include "AForm.hpp"

// class Bureaucrat;
class ShrubberyCreationForm : public AForm
{
    std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string tr);
        ShrubberyCreationForm(ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};


/// //////

/// ///////
// class PresidentialPardonForm : public AForm
// {
//     public:
//         PresidentialPardonForm();
//         PresidentialPardonForm(PresidentialPardonForm &copy);
//         PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
//         ~PresidentialPardonForm();
//         void execute(Bureaucrat const & executor) const;
// };

// PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", false, 25, 5) {}

// PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy) {}

// PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
//     if (this != &src)
//     {
//         AForm::operator=(src);
//     }
//     return *this;
// }

// PresidentialPardonForm::~PresidentialPardonForm() {}