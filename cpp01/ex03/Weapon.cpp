#include "Weapon.hpp"

std::string Weapon::getType(){
    return (type);
}

void Weapon::setType(std::string tp){
    type = tp;

}
Weapon::Weapon(std::string tp){
    type = tp;
}

Weapon::~Weapon(){}
Weapon::Weapon(){}