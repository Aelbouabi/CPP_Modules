#include "HumanA.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon*     piw;
    public:
        HumanB(std::string nm);
        ~HumanB();
        void setWeapon(Weapon& club);
        void attack();
};
