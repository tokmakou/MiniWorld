#include "shape.h"

Shape::Shape():
    _radius(0.0f)
{

}

Shape::Shape(float radius):
    _radius(radius){}

float Shape::radius() const
{
    return _radius;
}

void Shape::setRadius(float radius)
{
    _radius = radius;
}
