#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include "coordinate.h"
#include "velocity.h"
#include "shape.h"
#include "force.h"

class PhysicalObject
{
public:
    PhysicalObject();

    void Affect(const Force &, float dt);
    bool CollisionTest(const PhysicalObject &other, float timeTo,
                       float &contactTime, float &contactAngle) const;
    void Extrapolate(float dt);
    void Bump(PhysicalObject &other, float phi);

    Coordinate coordinate() const;
    void setCoordinate(const Coordinate &coordinate);

    Velocity velocity() const;
    void setVelocity(const Velocity &velocity);

    Shape shape() const;
    void setShape(const Shape &shape);

    float weight() const;
    void setWeight(float weight);

private:
    float _weight;
    Coordinate _coordinate;
    Velocity _velocity;
    Shape _shape;
};

#endif // PHYSICALOBJECT_H
