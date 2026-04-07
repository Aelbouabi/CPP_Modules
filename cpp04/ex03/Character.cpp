#include "Character.hpp"

Character::Character () : Name("") {
    for (int i = 0; i < 5; ++i)
        inventory[i] = NULL;
}

Character::Character (std::string name) : Name(name) {
    for (int i = 0; i < 5; ++i)
        inventory[i] = NULL;
}

Character &Character::operator=(const Character &src) {
    if(this != &src)
    {
        this->Name = src.Name;
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
            {
                delete inventory[i];
                this->inventory[i]  = NULL;
            }
            if (src.inventory[i])
                this->inventory[i] = src.inventory[i]->clone();
        }
    }
    return *this;
}

Character::Character(const Character &copy) {
	*this = copy;
}

Character::~Character () {
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
    for (int i = 0; i < 10000; i++)
    {
        if (to_destroy[i])
        {
            delete to_destroy[i];
            to_destroy[i] = NULL;
        }
        else
            break ;
    }
}

std::string const & Character::getName() const {
    return (this->Name);
}

int check_on(AMateria* m, AMateria** to_destroy)
{
    for (int j = 0; j < 10000; j++)
    {
        if (!to_destroy[j])
            break ;
        if (m == to_destroy[j])
           return (1);
    }
    return(0);
}

void Character::equip(AMateria* m) {
    int on = check_on(m, to_destroy);
    for (int i = 0; i < 4; i++)
    {
        if (m && !inventory[i])
        {
            inventory[i] = m->clone();
            break ;
        }
    }
    if (!on && m)
    {
        for (int i = 0; i < 10000; i++)
        {
            if (!to_destroy[i])
            {
                to_destroy[i] = m;
                break ;
            }
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
    {
        for (int i = 0; i < 10000; i++)
        {
            if (!to_destroy[i])
            {
                to_destroy[i] = inventory[idx];
                break ;
            }
        }
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if ((idx >= 0 && idx < 4) && inventory[idx])
        this->inventory[idx]->use(target);
}
