#include <iostream>

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
        std::string const getName();
        int getGrade();
        void Inc_Grade();
        void Dec_Grade();
        
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

std::ostream  &operator<<(std::ostream &out, Bureaucrat &src);
