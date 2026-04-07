#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string Name;
        bool sign;
        const int grad_sign;
        const int grad_ex;
    public:
        Form();
        Form(std::string nm, bool sg, int gs, int ge);
        const std::string getName();
        bool getSign();
         int getGrad_Sign() const;
         int getGrad_Ex();
        Form &operator=(const Form &src);
        Form(const Form &copy);
        ~Form();
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
};

std::ostream  &operator<<(std::ostream &out, Form &src);