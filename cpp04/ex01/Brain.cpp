#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Default Constructor created" << std::endl;
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &src) {
    std::cout << "Brain Copy Assigment Operator called" << std::endl;
    if(this != &src)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout<< "Brain has been destroyed" << std::endl;
}

