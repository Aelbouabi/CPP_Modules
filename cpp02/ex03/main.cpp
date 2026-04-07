#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {

    bool i =  bsp(Point(20, 20), Point(40 , 27), Point(26 , 35), Point(34 , 25));
    if (i)
        std::cout << "inside a triangle"  << std::endl;
    else  
        std::cout << "outside a triangle"  << std::endl;
    return 0;
}