#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
    : x(0), y(0)
{}

Point::Point(const float &a, const float &b)
    : x(a), y(b)
{}

Point::Point(const Point &p)
    : x(p.x), y(p.y)
{}

Point::~Point()
{}

Point Point::operator-(Point const &rhs) const 
{
    float new_x = this->x.toFloat() - rhs.x.toFloat();
    float new_y = this->y.toFloat() - rhs.y.toFloat();

    return Point(new_x, new_y);
}

Point Point::normal() const
{
        return Point( -y.toFloat(), x.toFloat());
}

float Point::dot(Point const &other_point) const
{
    return x.toFloat() * other_point.x.toFloat() + y.toFloat() * other_point.y.toFloat();
}
