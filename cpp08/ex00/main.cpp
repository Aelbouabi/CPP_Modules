#include "easyfind.hpp"
#include <vector>

int main ()
{
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(5);
        v.push_back(8);
        v.push_back(-1);
        v.push_back(7);
        v.push_back(9);
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << it[0] << std::endl;
        it[0] = 10;
        (it)++;
        std::cout << it[0] << std::endl;
        std::cout << v[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}