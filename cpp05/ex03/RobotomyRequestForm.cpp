#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Roboto", false, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string tr) : AForm("Roboto", false, 72, 45) {
    target = tr;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static int i;
    if (!getGrad_Sign())
        throw GradeTooLowException();
    if (executor.getGrade() > getGrad_Ex())
        throw GradeTooLowException();
    std::cout << "'Q...Q..TAN'  drilling noises." << std::endl;
    if (i % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << " the robotomy failed." << std::endl;
    i++;
}