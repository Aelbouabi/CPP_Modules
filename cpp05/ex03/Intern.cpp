#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern & Intern::operator=(const Intern &src)
{
    (void) src;
    return *this;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

const char* Intern::InternExc::what() const throw() {
    return "No form like that!!?";
}

AForm *president(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *roboto(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *shrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    AForm *(*forms[])(const std::string target) = {&shrubbery, &roboto, &president};
    std::string tr[3] = {"shrubbery creation" ,"robotomy request", "presidential pardon"};
    for (int i = 0; i < 4; i++)
    {
        if (form_name == tr[i])
        {
            return forms[i](target);
        }
    }
    throw InternExc();
}