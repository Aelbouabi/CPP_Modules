#pragma once
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &copy);
        Ice &operator=(const Ice &src);
        ~Ice();
        Ice(std::string const & type);
        AMateria* clone() const;
        void use(ICharacter& target);
};
