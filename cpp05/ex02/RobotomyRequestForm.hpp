#pragma once
#include "AForm.hpp"

// class Bureaucrat;
class RobotomyRequestForm : public AForm
{
    std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string tr);
        RobotomyRequestForm(RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};
