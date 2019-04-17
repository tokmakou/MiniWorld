#include <iostream>
#include <thread>
#include <chrono>
#include "src/physicalobject.h"
#include "src/miniworld.h"
#include <cmath>
#include <memory>

int main()
{

    MiniWorld miniWorld;

    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());
    miniWorld.AddPhysicalObject(std::make_shared<PhysicalObject>());

    std::shared_ptr<PhysicalObject> object1 = std::make_shared<PhysicalObject>();
    std::shared_ptr<PhysicalObject> object2 = std::make_shared<PhysicalObject>();
    std::shared_ptr<PhysicalObject> object3 = std::make_shared<PhysicalObject>();
    std::shared_ptr<PhysicalObject> object4 = std::make_shared<PhysicalObject>();

    miniWorld.AddPhysicalObject(object1);
    miniWorld.AddPhysicalObject(object2);
    miniWorld.AddPhysicalObject(object3);
    miniWorld.AddPhysicalObject(object4);

    object1->setCoordinate(Coordinate(0.0f, 0.0f));
    object2->setCoordinate(Coordinate(5.0f, 0.0f));

    object1->setShape(Shape(1));
    object2->setShape(Shape(1));

    object1->setVelocity(Velocity(1.0f, 1.0f));
    object2->setVelocity(Velocity(-1.0f, 1.0f));

    object3->setCoordinate(Coordinate(0.0f, 0.0f));
    object4->setCoordinate(Coordinate(5.0f, 0.0f));

    object3->setShape(Shape(1));
    object4->setShape(Shape(1));

    object3->setVelocity(Velocity(1.0f, 1.0f));
    object4->setVelocity(Velocity(-1.0f, 1.0f));

    float time = 0.0f;

    while (time < 10.5f) {
        std::cout<<time<<"\t"<<object1->coordinate().x()<<" "<<object1->coordinate().y()<<"\t"<<object2->coordinate().x()<<" "<<object2->coordinate().y()
                <<std::endl;
        time += 0.1f;

        miniWorld.Update(0.1f);
    }

    return 0;
}
