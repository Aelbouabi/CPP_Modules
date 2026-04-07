 #include "Ice.hpp"

Ice::Ice () {
    this->type = "ice";
}

Ice::Ice (std::string const & type) {
    this->type = type;
}

Ice &Ice::operator=(const Ice &src) {
    if(this != &src)
        this->type = src.type;
    return *this;
}

Ice::Ice(const Ice &copy) : AMateria (copy) {
	*this = copy;
}

Ice::~Ice () {
}

AMateria* Ice::clone() const {
     return (new Ice());
}

void Ice::use(ICharacter& target) {
    std::cout << "Ice: * shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}
