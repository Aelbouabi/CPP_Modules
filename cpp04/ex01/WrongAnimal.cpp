#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal Default Constructor created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
    std::cout << "WrongAnimal Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->type = src.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout<< "WrongAnimal has been destroyed" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal make sound RRR" << std::endl;
}

std::string WrongAnimal::getType() const{
    return (this->type);
}