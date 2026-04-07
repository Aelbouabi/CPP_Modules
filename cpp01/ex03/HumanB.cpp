#include "HumanB.hpp"

HumanB::HumanB(std::string nm) {
    name = nm;
    piw = NULL;
}

HumanB::~HumanB(){
}

void HumanB::attack() {
    if (!piw)
        std::cout << name << " can't attack because he don't have any weapon" <<std::endl;
    else
    std::cout << name << " attacks with their " << piw->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& club) {
    piw = &club;
}