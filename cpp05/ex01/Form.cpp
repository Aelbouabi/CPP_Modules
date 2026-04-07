#include "Form.hpp"

Form::Form() : Name("plag_form"),  sign(0), grad_sign(50), grad_ex(10) {}

Form::Form(std::string nm, bool sg, int gs, int ge) : Name(nm), grad_sign(gs), grad_ex(ge)  {
    sign = sg;
}

Form &Form::operator=(const Form &src) {
    if (this != &src)
    {
        this->sign = src.sign;
    }
    return *this;
}

Form::Form(const Form &copy) : grad_sign(copy.grad_sign), grad_ex(copy.grad_ex) {
    *this = copy;
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too High";
}

Form::~Form() {
}

void Form::beSigned(Bureaucrat &Bc) {
    if (Bc.getGrade() > grad_sign) {
        throw GradeTooLowException();
    }
    this->sign = true;
    std::cout << Bc.getName() << "  signed  " << this->Name << std::endl;
}

const std::string Form::getName()
{
    return Name;
}
bool Form::getSign()
{
    return sign;
}
 int Form::getGrad_Sign() const
{
    return grad_sign;
}
 int Form::getGrad_Ex()
{
    return grad_ex;
}

std::ostream  &operator<<(std::ostream &out, Form &src)
{
	out << src.getName() << ", Grad to sign is : " 
    << src.getGrad_Sign()<<", Grad to execute is : " 
    << src.getGrad_Ex() << ", form is sign : " << src.getSign();
	return out;
}