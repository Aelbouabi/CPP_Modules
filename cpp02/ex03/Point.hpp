#include "Fixed.hpp"

class Point
{
private:
    Fixed p_x;
    Fixed p_y;
public:
    Point(const float x, const float y);
    Point();
    Point (const Point& copy);
    ~Point();
    Point &operator=(const Point& src);
    const Fixed &get_x()const;
    const Fixed &get_y()const;
};
