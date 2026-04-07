#include "FragTrap.hpp"

FragTrap:: FragTrap(std::string nm): ClapTrap (nm)
{
    this->Hit_p = 100;
    this->Energy_p = 100;
    this->Attack_d = 30;
	std::cout << " FragTrap "<< this->Name <<" Constructor created\n" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<< "FragTrap " << this->Name << " has been destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(this->Name)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = copy;
}

void FragTrap::highFivesGuys()
{
    std::cout<< "FragTrap " << this->Name << " positive high fives request! 🙏" << std::endl;
}

FragTrap:: FragTrap()
{
    this->Hit_p = 100;
    this->Energy_p = 100;
    this->Attack_d = 30;
	std::cout << " FragTrap Default Constructor created\n" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->Name = src.Name;
    return *this;
}