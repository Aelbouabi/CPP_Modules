#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    std::string getType();
    void setType(std::string tp);
    Weapon(std::string tp);
    Weapon();
    ~Weapon();
};
