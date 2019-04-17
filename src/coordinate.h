#ifndef COORDINATE_H
#define COORDINATE_H


class Coordinate
{
public:
    Coordinate();
    Coordinate(float x, float y);

    float Distance(const Coordinate &other);

    float x() const;
    void setX(float x);

    float y() const;
    void setY(float y);

private:
    float _x;
    float _y;
};

#endif // COORDINATE_H
