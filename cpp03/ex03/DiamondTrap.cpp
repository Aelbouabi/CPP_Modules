#include "DiamondTrap.hpp"

DiamondTrap:: DiamondTrap(std::string nm) : ClapTrap (nm + "_clap_name")
{
    this->Hit_p = 100;
    this->Energy_p = 50;
    this->Attack_d = 30;
	this->Name = nm;
	std::cout << " DiamondTrap "<< this->Name <<" Constructor created\n" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout<< "DiamondTrap " << this->Name << " has been destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(this->Name) , ScavTrap(this->Name) , FragTrap(this->Name)
{
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    std::cout << "DiamondTrap Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->Name = src.Name;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}

DiamondTrap:: DiamondTrap() : ClapTrap ("_clap_name")
{
    this->Hit_p = 100;
    this->Energy_p = 50;
    this->Attack_d = 30;
	this->Name = "\0";
	std::cout << " DiamondTrap "<< this->Name <<" Constructor created\n" << std::endl;
}