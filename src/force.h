#ifndef FORCE_H
#define FORCE_H


class Force
{
public:
    Force();
    Force(float forceX, float forceY):
        _forceX (forceX),
        _forceY (forceY)
    {}

    float forceX() const;
    void setForceX(float forceX);

    float forceY() const;
    void setForceY(float forceY);

    inline static Force ForceOfGravity(float weight){
        return Force(0, weight * -9.8066f);
    }

private:
    float _forceX;
    float _forceY;
};

#endif // FORCE_H
