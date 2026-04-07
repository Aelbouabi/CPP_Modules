#include "AForm.hpp"

AForm::AForm() : Name("plag_form"),  sign(0), grad_sign(50), grad_ex(10) {}

AForm::AForm(std::string nm, bool sg, int gs, int ge) : Name(nm), grad_sign(gs), grad_ex(ge)  {
    sign = sg;
}

AForm &AForm::operator=(const AForm &src) {
    if (this != &src)
    {
        this->sign = src.sign;
    }
    return *this;
}

AForm::AForm(const AForm &copy) : grad_sign(copy.grad_sign), grad_ex(copy.grad_ex) {
    *this = copy;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too High";
}

AForm::~AForm() {
}

void AForm::beSigned(Bureaucrat &Bc) {
    if (Bc.getGrade() > grad_sign) {
        throw GradeTooLowException();
    }
    this->sign = true;
    std::cout << Bc.getName() << "signed" << this->Name;
}

std::string const AForm::getName() const
{
    return Name;
}

bool AForm::getSign()
{
    return sign;
}

int AForm::getGrad_Sign() const
{
    return grad_sign;
}

int AForm::getGrad_Ex() const
{
    return grad_ex;
}

std::ostream  &operator<<(std::ostream &out, AForm &src)
{
	out << src.getName() << ", Grad to sign is : " 
    << src.getGrad_Sign()<<", Grad to execute is : " 
    << src.getGrad_Ex() << ", form is sign : " << src.getSign();
	return out;
}