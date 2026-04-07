#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:
        
    public:
        FragTrap(std::string nm);
		~FragTrap();
		FragTrap(const FragTrap &tm);
        FragTrap();
        FragTrap &operator=(const FragTrap &src);
        void highFivesGuys(void);
};
