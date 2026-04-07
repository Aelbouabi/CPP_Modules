#include "ClapTrap.hpp"

class  ScavTrap : virtual public ClapTrap
{
	private:
		
	public:
		ScavTrap(std::string nm);
		~ScavTrap();
		ScavTrap(const ScavTrap &tm);
		ScavTrap();
		ScavTrap &operator=(const ScavTrap &src);
		void attack(const std::string& target);
        void guardGate();
};


