#include "ScavTrap.hpp"

ScavTrap:: ScavTrap(std::string nm) : ClapTrap(nm)
{
    this->Hit_p = 100;
    this->Energy_p = 50;
    this->Attack_d = 20;
	std::cout << " ScavTrap "<< this->Name <<" Constructor created\n" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<< "ScavTrap " << this->Name << " has been destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout<< "ScavTrap " << this->Name << "  is now in Gate keeper mode" << std::endl;
}

ScavTrap:: ScavTrap(){
	this->Hit_p = 100;
	this->Energy_p = 50;
	this->Attack_d = 20;
	std::cout << "ScavTrap Default Constructor created\n" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!Hit_p || !Energy_p)
	{
		std::cout << "!!!can't Attack!!!\nScavTrap has just " << this->Hit_p << " HP And " << this->Energy_p
		<< " Energy points.\n" << std::endl;
		return ;
	}
	this->Energy_p--;
	std::cout << "ScavTrap " << this->Name << " attacks " << target <<" , causing "
	<< this->Attack_d <<" points of damage! Energy points = " << this->Energy_p << "\n" <<std::endl;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->Name = src.Name;
    return *this;
}

