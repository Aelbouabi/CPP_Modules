#include "typeinfo.hpp"

Base::~Base() {}

Base * generate(void)
{
    std::srand(std::time(NULL));
    int i = std::rand() % 3;
    if (i == 0)
        return new A();
    if (i == 1)
        return new B();
    if (i == 2)
        return new C(); 
    return new A(); 
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "pointer type is A()" << std::endl;
        return ;
    }
    if (dynamic_cast<B*>(p))
    {
        std::cout << "pointer type is B()" << std::endl;
        return ;
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "pointer type is C()" << std::endl;
        return ;
    }
    std::cout << "***no such a type***" << std::endl;
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "pointer type is A()" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "pointer type is B()" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "pointer type is C()" << std::endl;
        return ;
    }
    catch(const std::exception& e){
        std::cout << "***no such a type***" << std::endl;
    }
}
