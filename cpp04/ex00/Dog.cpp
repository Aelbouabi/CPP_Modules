#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog Default Constructor created" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    std::cout << "Dog Copy Constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &src) {
    std::cout << "Dog Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->type = src.type;
    return *this;
}

Dog::~Dog() {
    std::cout<< "Dog has been destroyed" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog Bark" << std::endl;
}
