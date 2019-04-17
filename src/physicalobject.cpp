#include "physicalobject.h"
#include <utility>
#include <cmath>
#include <cassert>
#include <iostream>

const float EPS = 0.000001f;

PhysicalObject::PhysicalObject():
    _weight(EPS)
{

}

void PhysicalObject::Affect(const Force &force, float dt)
{
    _coordinate.setX(_coordinate.x() + _velocity.speedX() * dt
                     + force.forceX() * dt * dt / 2 / _weight);
    _coordinate.setY(_coordinate.y() + _velocity.speedY() * dt
                     + force.forceY() * dt * dt / 2 / _weight);

    _velocity.setSpeedX(_velocity.speedX() + force.forceX() * dt / _weight);
    _velocity.setSpeedY(_velocity.speedY() + force.forceY() * dt / _weight);
}

bool PhysicalObject::CollisionTest(const PhysicalObject &other, float timeTo,
                                   float &contactTime, float &contactAngle) const{

    float x1 = _coordinate.x();
    float x2 = other.coordinate().x();
    float y1 = _coordinate.y();
    float y2 = other.coordinate().y();

    float v1x = _velocity.speedX();
    float v2x = other.velocity().speedX();
    float v1y = _velocity.speedY();
    float v2y = other.velocity().speedY();

    float r1 = _shape.radius();
    float r2 = other.shape().radius();


    // если объекты не движутся параллельно
    if  ((v1x - v2x) * (v1x - v2x) + (v1y - v2y) * (v1y - v2y) > EPS){

        // находим время, при котором расстояние между объектами минимальное
        // (точка, где производная расстояния равна нулю (функция расстояния имеет только один экстремум - минимум))
        float t = -(2*(v1x - v2x)*(x1 - x2) + 2*(v1y - v2y)*(y1 - y2))/(2*(v1x - v2x)*(v1x - v2x)
                                                                        + 2*(v1y - v2y)*(v1y - v2y));

        // теперь находим минимальное расстояние между объектами в это время
        float minimumDistanceBetweenObjects = std::sqrt((x1 + v1x * t - x2 - v2x * t) * (x1 + v1x * t - x2 - v2x * t)
                                                        + (y1 + v1y * t - y2 - v2y * t) * (y1 + v1y * t - y2 - v2y * t));

        // если минимальное расстояние удовлетворяет условию пересечения
        if (minimumDistanceBetweenObjects < r1 + r2){
            // время контакта
            contactTime = -(v1x*x1 - v1x*x2 - v2x*x1 + v2x*x2 + v1y*y1 - v1y*y2 - v2y*y1 + v2y*y2
                            + std::sqrt(r1*r1*v1x*v1x - 2*r1*r1*v1x*v2x + r1*r1*v2x*v2x + r1*r1*v1y*v1y
                                        - 2*r1*r1*v1y*v2y + r1*r1*v2y*v2y + 2*r1*r2*v1x*v1x - 4*r1*r2*v1x*v2x
                                        + 2*r1*r2*v2x*v2x + 2*r1*r2*v1y*v1y - 4*r1*r2*v1y*v2y + 2*r1*r2*v2y*v2y
                                        + r2*r2*v1x*v1x - 2*r2*r2*v1x*v2x + r2*r2*v2x*v2x + r2*r2*v1y*v1y
                                        - 2*r2*r2*v1y*v2y + r2*r2*v2y*v2y - v1x*v1x*y1*y1 + 2*v1x*v1x*y1*y2
                                        - v1x*v1x*y2*y2 + 2*v1x*v2x*y1*y1 - 4*v1x*v2x*y1*y2 + 2*v1x*v2x*y2*y2
                                        + 2*v1x*v1y*x1*y1 - 2*v1x*v1y*x1*y2 - 2*v1x*v1y*x2*y1 + 2*v1x*v1y*x2*y2
                                        - 2*v1x*v2y*x1*y1 + 2*v1x*v2y*x1*y2 + 2*v1x*v2y*x2*y1 - 2*v1x*v2y*x2*y2
                                        - v2x*v2x*y1*y1 + 2*v2x*v2x*y1*y2 - v2x*v2x*y2*y2 - 2*v2x*v1y*x1*y1
                                        + 2*v2x*v1y*x1*y2 + 2*v2x*v1y*x2*y1 - 2*v2x*v1y*x2*y2 + 2*v2x*v2y*x1*y1
                                        - 2*v2x*v2y*x1*y2 - 2*v2x*v2y*x2*y1 + 2*v2x*v2y*x2*y2 - v1y*v1y*x1*x1
                                        + 2*v1y*v1y*x1*x2 - v1y*v1y*x2*x2 + 2*v1y*v2y*x1*x1 - 4*v1y*v2y*x1*x2
                                        + 2*v1y*v2y*x2*x2 - v2y*v2y*x1*x1 + 2*v2y*v2y*x1*x2 - v2y*v2y*x2*x2))
                    /(v1x*v1x - 2*v1x*v2x + v2x*v2x + v1y*v1y - 2*v1y*v2y + v2y*v2y);

            // когда объекты проходят совсем близко друг к другу, contactTime может быть isNan(float, что уж тут поделать???)
            if (std::isnan(contactTime))
                return false;

            // если время контакта не приходится на проверяемое время
            if (0.0f > contactTime || contactTime > timeTo)
                return false;

            // перпендикуляр к углу наклона касательных при контакте
            contactAngle = float(atan2(double((y1 + v1y * contactTime) - (y2 + v2y * contactTime)),
                                       double((x1 + v1x * contactTime) - (x2 + v2x * contactTime))));
        }
        // объекты никогда не перескутся друг с другом
        else return false;
    }
    else
        // объекты могут находиться друг на дружке при неправильной инициализации и двигаться параллельно
        // выталкиваем объекты прямо сейчас
        if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < (r1 + r2)*(r1 + r2))
        {
            contactTime = 0.0f;
            contactAngle = float(atan2(double((y1 + v1y * contactTime) - (y2 + v2y * contactTime)),
                                       double((x1 + v1x * contactTime) - (x2 + v2x * contactTime))) + M_PI_2);
        }
        else {
            return false;
        }
    return true;
}

void PhysicalObject::Extrapolate(float dt)
{
    _coordinate.setX(_coordinate.x() + _velocity.speedX() * dt);
    _coordinate.setY(_coordinate.y() + _velocity.speedY() * dt);
}

void PhysicalObject::Bump(PhysicalObject &other, float phi){
    // https://en.wikipedia.org/wiki/Elastic_collision

    float m1 = _weight;
    float m2 = other._weight;
    float v1 = _velocity.ScalarSize();
    float v2 = other.velocity().ScalarSize();
    float theta1 = _velocity.getHeading();
    float theta2 = other.velocity().getHeading();

    float cosTheta1MinusPhi = std::cos(theta1 - phi);
    float cosTheta2MinusPhi = std::cos(theta2 - phi);
    float sinTheta1MinusPhi = std::sin(theta1 - phi);
    float sinTheta2MinusPhi = std::sin(theta2 - phi);
    float cosPhi = std::cos(phi);
    float sinPhi = std::sin(phi);

    float start = v1 * cosTheta1MinusPhi * (m1 - m2) + 2.0f * m2 * v2 * cosTheta2MinusPhi;
    float vx1 = (start) * cosPhi / (m1 + m2) + v1*sinTheta1MinusPhi*sinPhi;
    float vy1 = (start) * sinPhi / (m1 + m2) + v1*sinTheta1MinusPhi*cosPhi;

    start = v2 * cosTheta2MinusPhi * (m2 - m1) + 2.0f * m1 * v1 * cosTheta1MinusPhi;
    float vx2 = (start) * cosPhi / (m1 + m2) + v2*sinTheta2MinusPhi*sinPhi;
    float vy2 = (start) * sinPhi / (m1 + m2) + v2*sinTheta2MinusPhi*cosPhi;

    _velocity = Velocity(vx1, vy1);
    other.setVelocity(Velocity(vx2, vy2));

    if (_coordinate.Distance(other.coordinate()) < _shape.radius() + other.shape().radius())
    {
        _coordinate.setX(_coordinate.x() + (_shape.radius() + other.shape().radius()));
        _coordinate.setY(_coordinate.y() + (_shape.radius() + other.shape().radius()));
    }
}

Coordinate PhysicalObject::coordinate() const
{
    return _coordinate;
}

void PhysicalObject::setCoordinate(const Coordinate &coordinate)
{
    _coordinate = coordinate;
}

Velocity PhysicalObject::velocity() const
{
    return _velocity;
}

void PhysicalObject::setVelocity(const Velocity &velocity)
{
    _velocity = velocity;
}

Shape PhysicalObject::shape() const
{
    return _shape;
}

void PhysicalObject::setShape(const Shape &shape)
{
    _shape = shape;
}

float PhysicalObject::weight() const
{
    return _weight;
}

void PhysicalObject::setWeight(float weight)
{
    _weight = weight > EPS ? weight : EPS;
}
