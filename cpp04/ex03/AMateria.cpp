#include "AMateria.hpp"

AMateria::AMateria () {
    this->type = "\0";
}

AMateria::AMateria (std::string const & type) {
    this->type = type;
}

AMateria &AMateria::operator=(const AMateria &src) {
    if(this != &src)
        this->type = src.type;
    return *this;
}

AMateria::AMateria(const AMateria &copy) {
	*this = copy;
}

AMateria::~AMateria () {
}

std::string const & AMateria::getType() const {
    return(this->type);
}

void AMateria::use(ICharacter& target) {
    (void)target;
}