#include "iter.hpp"

void print_int(int nb)
{
    static int i;
    std::cout << "array [" << i << "] : " << nb << std :: endl;
    i++;
}

void print_char(char c)
{
    static int i;
    std::cout << "array [" << i << "] : " << c << std :: endl;
    i++;
}

void Positive_nbr(int nb)
{
    static int i;
    if (nb < 0)
        nb *= -1;
    std::cout << "array [" << i << "] : " << nb << std :: endl;
    i++;
}

int main( void ) {

    int *a = new int[7];
    a[0] = 54;
    a[1] = 7;
    a[2] = 4;
    a[3] = 5;
    a[4] = -154;
    a[5] = 94;
    a[6] = 32;

    const char *c = "Hello World!";
    ::iter(a, 7, print_int);
    std::cout << std::endl;
    ::iter(a, 7, Positive_nbr);
    std::cout << std::endl;
    ::iter(c, 12, print_char);
    delete[] a;
    return 0;
}