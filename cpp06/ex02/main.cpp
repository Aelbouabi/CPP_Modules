#include "typeinfo.hpp"

int main()
{
    Base *p = generate();
    Base *n = NULL;
    identify(p);
    identify(n);
    identify(*p);
    identify(*n);
    delete p;
}