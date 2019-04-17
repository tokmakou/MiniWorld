#include "miniworld.h"
#include <iostream>

MiniWorld::MiniWorld()
{

}

void MiniWorld::setBoudary(float height, float width){
    _isBoundary = true;
    _height = height;
    _width = width;
}

void MiniWorld::AddPhysicalObject(std::shared_ptr<PhysicalObject> object){
    _objects.insert(std::make_pair(object, 0.0f));
}

void MiniWorld::DeletePhysicalObject(std::shared_ptr<PhysicalObject> &object){
    _objects.erase(object);
}

void MiniWorld::Update(float dt){

    auto setRemainderTime = [dt](decltype (_objects)::value_type &node){
        node.second = dt;
    };
    std::for_each(_objects.begin(), _objects.end(), setRemainderTime);

    struct CollisionObject
    {
        std::shared_ptr<PhysicalObject> collisionObject;
        float collisionTime;
        float contactAngle;
    };
    std::map<decltype (_objects)::value_type::first_type, CollisionObject> collisions;

    do{
        auto iteratorCollision = collisions.begin();
        while (iteratorCollision != collisions.end()) {
            decltype (iteratorCollision) collisionObject = collisions.find(iteratorCollision->second.collisionObject);
            if (iteratorCollision->first == collisionObject->second.collisionObject)
            {
                iteratorCollision->first->Extrapolate(iteratorCollision->second.collisionTime);
                collisionObject->first->Extrapolate(iteratorCollision->second.collisionTime);
                iteratorCollision->first->Bump(collisionObject->first.operator*(),
                                                iteratorCollision->second.contactAngle);

                auto firstObject = _objects.find(iteratorCollision->first);
                auto secondObject = _objects.find(collisionObject->first);

                firstObject->second -= iteratorCollision->second.collisionTime;
                secondObject->second -= iteratorCollision->second.collisionTime;

                collisions.erase(collisionObject);
            }
            iteratorCollision = collisions.erase(iteratorCollision);
        }


        for (auto checkerObject = _objects.begin(), end = _objects.end(); checkerObject != end; ++checkerObject){
            auto checkingObject = checkerObject;
            float iteratorRemainderTime = checkerObject->second;
            for (checkingObject = ++checkingObject; checkingObject != end; ++checkingObject){
                float contactTime;
                float contactAngle;

                float minimumUpdateTime = (iteratorRemainderTime < checkingObject->second) ?
                            iteratorRemainderTime : checkingObject->second;

                if (checkerObject->first->CollisionTest(checkingObject->first.operator*(), minimumUpdateTime,
                                                        contactTime, contactAngle)){

                    auto first = collisions.emplace(std::make_pair(checkerObject->first,
                                                                   CollisionObject{checkingObject->first, contactTime, contactAngle})).first;
                    auto second = collisions.emplace(std::make_pair(checkingObject->first,
                                                                    CollisionObject{checkerObject->first, contactTime, contactAngle})).first;

                    if (contactTime < first->second.collisionTime)
                        first->second = CollisionObject{checkingObject->first, contactTime, contactAngle};

                    if (contactTime < second->second.collisionTime)
                        second->second = CollisionObject{checkerObject->first, contactTime, contactAngle};

                }
            }
        }
    } while (!collisions.empty());

    // экстраполируем то, что осталось без коллизий
    for (auto object: _objects){
        object.first->Extrapolate(object.second);}
}
