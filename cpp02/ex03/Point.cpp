#include "Point.hpp"

Point::Point ():p_x(), p_y(){}

Point::Point (const float x, const float y):p_x(x), p_y(y){}
Point::Point (const Point& copy)
{
    *this = copy;
}

Point  &Point::operator=(const Point& src)
{
    if (this != &src)
    {
        (Fixed) this->p_x = src.p_x;
        (Fixed) this->p_y = src.p_y;
    }
    return (*this);
}



Point ::~Point ()
{
}

const Fixed &Point::get_x()const
{
    return (this->p_x);
}

const Fixed &Point::get_y()const
{
    return (this->p_y);
}
