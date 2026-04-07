#include <iostream>

class ClapTrap
{
	protected:
		std::string Name;
		int Hit_p;
		int Energy_p;
		int Attack_d;
	public:
		ClapTrap(std::string nm);
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap &tm);
		ClapTrap &operator=(const ClapTrap &src);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};