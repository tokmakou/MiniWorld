#ifndef VELOCITY_H
#define VELOCITY_H


class Velocity
{
public:
    Velocity();
    Velocity(float speedX, float speedY);

    float speedX() const;
    void setSpeedX(float speedX);

    float speedY() const;
    void setSpeedY(float speedY);

    float getHeading();
    float ScalarSize();

private:
    float _speedX;
    float _speedY;
};

#endif // VELOCITY_H
