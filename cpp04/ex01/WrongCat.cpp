#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat Default Constructor created" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	std::cout << "WrongCat Copy Assigment Operator called" << std::endl;
	if(this != &src)
		this->type = src.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout<< "WrongCat has been destroyed" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat Meow" << std::endl;
}
