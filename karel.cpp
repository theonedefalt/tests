#include "karel.hpp"

void decorateWorld(const char *fileName)
{
    world->set(4, 4, HWALL);
    world->set(4, 4, VWALL);
    world->set(4, 4, BEEPER);
    world->save(fileName);
}

class MyRobot : public Robot
{
public:
    void turnRight()
    {
        if (checkStatus())
        {
            turnLeft();
            turnLeft();
            turnLeft();
        }
    }
};

int main()
{
    world->create("");
    decorateWorld("Guia0101.txt");
    world->show();
    world->reset();
    world->read("Guia0101.txt");
    world->show();
    set_Speed(3);
    MyRobot *robot = new MyRobot();
    robot->create(1, 1, EAST, 0, "Karel");
    robot->move();
    robot->move();
    robot->turnLeft();
    robot->move();
    robot->move();
    robot->turnLeft();
    robot->move();
    robot->move();
    robot->turnLeft();
    robot->move();
    robot->move();
    robot->turnLeft();
    robot->turnLeft();
    robot->turnOff();
    world->close();
    getchar();
    return (0);
}
