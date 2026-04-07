#include "Serializer.hpp"

int main ()
{
    Data *ptr = new Data;
    ptr->data = "adnan";
    uintptr_t i = Serializer::serialize(ptr);
    std::cout << "ptr = " << ptr->data << std::endl;
    std::cout << "i   = " << i << std::endl;
    ptr = Serializer::deserialize(i);
    std::cout << "ptr = " << ptr->data << std::endl;
    std::cout << "i   = " << i << std::endl;
    delete ptr;
}
