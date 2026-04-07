#pragma once
#include "Bureaucrat.hpp"
#include <iomanip>

class Bureaucrat;
class AForm
{
    private:
        const std::string Name;
        bool sign;
        const int grad_sign;
        const int grad_ex;
    public:
        AForm();
        AForm(std::string nm, bool sg, int gs, int ge);
        const std::string getName() const;
        bool getSign();
         int getGrad_Sign() const;
         int getGrad_Ex() const;
        AForm &operator=(const AForm &src);
        AForm(const AForm &copy);
        virtual ~AForm();
        void beSigned(Bureaucrat &Bc);
        class GradeTooHighException : public std::exception
        {
            public :
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream  &operator<<(std::ostream &out, AForm &src);
