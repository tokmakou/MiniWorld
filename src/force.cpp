#include "force.h"

Force::Force()
{

}

float Force::forceX() const
{
    return _forceX;
}

void Force::setForceX(float forceX)
{
    _forceX = forceX;
}

float Force::forceY() const
{
    return _forceY;
}

void Force::setForceY(float forceY)
{
    _forceY = forceY;
}
