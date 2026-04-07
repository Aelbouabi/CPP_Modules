#include "Cure.hpp"

Cure::Cure () {
    this->type = "cure";
}

Cure::Cure (std::string const & type) {
    this->type = type;
}

Cure &Cure::operator=(const Cure &src) {
    if(this != &src)
        this->type = src.type;
    return *this;
}

Cure::Cure(const Cure &copy) : AMateria (copy) {
}

Cure::~Cure () {
}

AMateria *Cure::clone() const {
     return (new Cure());
}

void Cure::use(ICharacter& target) {
    std::cout << "Cure: * heals "<< target.getName() <<"’s wounds *" << std::endl;
}
