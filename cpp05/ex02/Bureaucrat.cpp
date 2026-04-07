#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name("joseph"), grade(150) {}

Bureaucrat::Bureaucrat(std::string nm, int grd) : Name(nm) {
    if (grd > 150)
        throw GradeTooLowException();
    else if (grd < 1)
        throw GradeTooHighException();
    grade = grd;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    if (this != &src)
        this->grade = src.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
}

Bureaucrat::~Bureaucrat() {
}
std::string const Bureaucrat::getName() const {
    return Name;
}
int Bureaucrat::getGrade() const {
    return grade;
}
void Bureaucrat::Inc_Grade() {
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::Dec_Grade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
} 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too High";
}

std::ostream  &operator<<(std::ostream &out, Bureaucrat &src)
{
	out << src.getName() << ", Grad is : " << src.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
    }
    catch (const GradeTooLowException& e)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << ".";
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try 
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
