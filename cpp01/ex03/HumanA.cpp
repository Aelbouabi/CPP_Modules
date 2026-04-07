#include "HumanA.hpp"

void HumanA::attack() {
    std::cout << name << " attacks with their " << kl.getType() << std::endl;
}

HumanA::HumanA(std::string nm, Weapon& wp) : name(nm), kl(wp){}

HumanA::~HumanA(){
}