#include "Cat.hpp"

class Dog : public Animal
{
    private:
        Brain *br;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &src);
        ~Dog();
        void makeSound() const;
};
