#include "coordinate.h"
#include <cmath>

Coordinate::Coordinate():
    _x (0.0f),
    _y (0.0f)
{

}

Coordinate::Coordinate(float x, float y):
    _x(x),
    _y(y){}

float Coordinate::Distance(const Coordinate &other){
    return std::sqrt((_x - other._x) * (_x - other._x) - (_y - other._y) * (_y - other._y));
}

float Coordinate::x() const
{
    return _x;
}

void Coordinate::setX(float x)
{
    _x = x;
}

float Coordinate::y() const
{
    return _y;
}

void Coordinate::setY(float y)
{
    _y = y;
}
