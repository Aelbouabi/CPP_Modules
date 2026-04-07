#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", false, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tr) : AForm("Shrubbery", false, 145, 137) {
    target = tr;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getGrad_Sign())
        throw GradeTooLowException();
    if (executor.getGrade() > getGrad_Ex())
        throw GradeTooLowException();
    std::string f_name = target + "_shrubbery";
    std::ofstream File(f_name.c_str());
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            File << " ";
        }
        File << "/";
        for (int k = 0; k < 2 * i ; k++)
        {
            File << "*";
        }
        File << "\\";
        File << std::endl;
    }
    File << std::setw(n + 3) << "| |\n" ;
    File << std::setw(n + 3) << "| |\n" ;
    File.close();
}
