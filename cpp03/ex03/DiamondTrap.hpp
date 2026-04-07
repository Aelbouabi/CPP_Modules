#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
    private:
        std::string Name;
    public:
        DiamondTrap(std::string nm);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &src);
        void whoAmI();
};
