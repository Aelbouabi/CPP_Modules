#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon&     kl;
    public:
        HumanA(std::string nm, Weapon& wp);
        ~HumanA();
        void attack();
};