#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
    protected:
        std::string Name;
        AMateria* inventory[5];
        static AMateria* to_destroy[10000];
    public:
        Character();
        Character(std::string name);
        Character(const Character &copy);
        Character &operator=(const Character &src);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
