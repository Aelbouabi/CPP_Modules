#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        std::string const Name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string nm, int grd);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();
        std::string const getName() const;
        int getGrade() const;
        void Inc_Grade();
        void Dec_Grade();
        void signForm(AForm &form);
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
        void executeForm(AForm const & form);
};

std::ostream  &operator<<(std::ostream &out, Bureaucrat &src);


