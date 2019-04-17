#ifndef SHAPE_H
#define SHAPE_H

//
// Пока только форма круга, в дальнейшем можно
// расширить через позже созданный интерфейс Shape
//
class Shape
{
public:
    Shape();
    Shape(float radius);

    float radius() const;
    void setRadius(float radius);

private:
    float _radius;
};

#endif // SHAPE_H
