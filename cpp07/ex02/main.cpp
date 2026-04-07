#include "Array.hpp"

int main()
{
    try
    {
        Array<int> arr(5);
        std::cout << "arr : " << arr[0] << std::endl;
        std::cout << "arr : " << arr[1] << std::endl;
        std::cout << "arr : " << arr[2] << std::endl;
        std::cout << "arr : " << arr[3] << std::endl;
        std::cout << "arr : " << arr[5] << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Array<int> a;
        std::cout << "a   : " << a[0] << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}