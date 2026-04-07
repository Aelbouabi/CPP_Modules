#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat Default Constructor created" << std::endl;
    type = "Cat";
    br = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat Copy Constructor called" << std::endl;
    br = new Brain();
	*this = copy;
}

Cat &Cat::operator=(const Cat &src) {
    std::cout << "Cat Copy Assigment Operator called" << std::endl;
    if(this != &src)
    {
        this->type = src.type;
        this->br = src.br;
    }
    return *this;
}

Cat::~Cat() {
    std::cout<< "Cat has been destroyed" << std::endl;
    delete br;
}

void Cat::makeSound() const{
    std::cout << "Cat Meow" << std::endl;
}
