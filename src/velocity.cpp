#include "velocity.h"
#include <cmath>

Velocity::Velocity():
    _speedX (0.0f),
    _speedY (0.0f)
{

}

Velocity::Velocity(float speedX, float speedY):
    _speedX(speedX),
    _speedY(speedY)
{}

float Velocity::speedX() const
{
    return _speedX;
}

void Velocity::setSpeedX(float speedX)
{
    _speedX = speedX;
}

float Velocity::speedY() const
{
    return _speedY;
}

void Velocity::setSpeedY(float speedY)
{
    _speedY = speedY;
}

float Velocity::getHeading(){
    return std::atan2(_speedY, _speedX);
}

float Velocity::ScalarSize(){
    return std::sqrt(_speedX * _speedX + _speedY * _speedY);
}
