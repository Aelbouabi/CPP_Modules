#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal Default Constructor created" << std::endl;
}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &src) {
    std::cout << "Animal Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->type = src.type;
    return *this;
}

Animal::~Animal() {
    std::cout<< "Animal has been destroyed" << std::endl;
}

std::string Animal::getType() const{
    return (this->type);
}