#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string nm) : Hit_p(10), Energy_p(10), Attack_d(0)
{
	this->Name = nm;
	std::cout << "ClapTrap "<< this->Name <<" Constructor created\n" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->Name << "ClapTrap has been destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!Hit_p || !Energy_p)
	{
		std::cout << "!!!can't Attack!!!\nClapTrap has just " << this->Hit_p << " HP And " << this->Energy_p
		<< " Energy points.\n" << std::endl;
		return ;
	}
	this->Energy_p--;
	std::cout << "ClapTrap " << this->Name << " attacks " << target <<" , causing "
	<< this->Attack_d <<" points of damage! Energy points = " << this->Energy_p << "\n" <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = copy;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!Hit_p || !Energy_p)
	{

		std::cout<<  "!!!can't Repair!!!\n" << "ClapTrap has " << this->Hit_p << " HP And " << this->Energy_p
		<< " Energy points.\n" << std::endl;
		return ;
	}
	this->Hit_p = this->Hit_p + amount;
	this->Energy_p--;
	std::cout << "ClapTrap " << this->Name << " beRepaird " << amount 
	<< " hit_point. HP = "<< this->Hit_p << " Energy points = "
	<< this->Energy_p << "\n" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!Hit_p)
	{
		std::cout << "ClapTrap is already dead " << this->Hit_p << " HP\n" << std::endl;
		return ;
	}
	if ((int)amount > this->Hit_p)
		this->Hit_p = 0;
	else
		this->Hit_p = this->Hit_p - amount;
	std::cout << "ClapTrap " << this->Name << " take " << amount 
	<< " Damage. HP = "<< this->Hit_p << " Energy points = "
	<< this->Energy_p << "\n" << std::endl;
}

ClapTrap::ClapTrap() : Hit_p(10), Energy_p(10), Attack_d(0){
	this->Name = "\0";
	std::cout << "ClapTrap Default Constructor created\n" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "ClapTrap Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->Name = src.Name;
    return *this;
}
