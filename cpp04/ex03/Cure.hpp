#pragma once
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &copy);
        Cure &operator=(const Cure &src);
        ~Cure();
        Cure(std::string const & type);
        AMateria* clone() const;
        void use(ICharacter& target);
};
