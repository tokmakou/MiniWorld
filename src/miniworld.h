#ifndef MINIWORLD_H
#define MINIWORLD_H

#include "physicalobject.h"

#include <memory>
#include <unordered_map>
#include <map>
#include <list>
#include <algorithm>

class MiniWorld
{
public:
    MiniWorld();

    void setBoudary(float height, float width);

    void AddPhysicalObject(std::shared_ptr<PhysicalObject> object);

    void DeletePhysicalObject(std::shared_ptr<PhysicalObject> &object);

    void Update(float dt);

private:

    bool _isBoundary = false;
    float _height;
    float _width;

    std::unordered_map<std::shared_ptr<PhysicalObject>, float> _objects;
};

#endif // MINIWORLD_H
