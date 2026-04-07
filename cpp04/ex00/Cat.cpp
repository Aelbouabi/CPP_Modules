#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat Default Constructor created" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &src) {
    std::cout << "Cat Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->type = src.type;
    return *this;
}

Cat::~Cat() {
    std::cout<< "Cat has been destroyed" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat Meow" << std::endl;
}
