#include "Point.hpp"


float triangle_surface(Point const& a, Point const& b, Point const& c)
{
    float res;
    float ab;

    res = (a.get_x().toFloat()*(b.get_y().toFloat()- c.get_y().toFloat()) +
           b.get_x().toFloat()*(c.get_y().toFloat()- a.get_y().toFloat()) +  
           c.get_x().toFloat()*(a.get_y().toFloat()- b.get_y().toFloat()) )/2;
    ab = std::fabs(res);
    return ab;
}



bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float triangle, triangle1,triangle2,triangle3;
    triangle = triangle_surface(a,b,c);
    triangle1 = triangle_surface(point,a,b);
    triangle2 = triangle_surface(point,a,c);
    triangle3 = triangle_surface(point,b,c);

    if (!triangle || !triangle1 || !triangle2 || !triangle3)
        return false;
    else if (triangle1 + triangle2 + triangle3 != triangle)
        return false;
    return true;
}
