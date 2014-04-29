#include "particle2d.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

particle2d::particle2d()
{
    setPosition(0, 0);
}

particle2d::particle2d(glm::vec2 location)
{
    setPosition(location);
}

particle2d::particle2d(int x, int y)
{
    setPosition(x, y);
}

void particle2d::computePosition()
{
    setPosition(glm::vec2(x,y)+glm::vec2(speedx, speedy));
}

void particle2d::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void particle2d::setPosition(glm::vec2 position)
{
    this->x = position.x;
    this->y = position.y;
}

void particle2d::setSpeed(glm::vec2 speed)
{
    this->speedx = speed.x;
    this->speedy = speed.y;
}

void particle2d::setSpeed(float sx, float sy)
{
    speedx = sx;
    speedy = sy;
}

int particle2d::computeSum()
{
    return x+y;
}

glm::vec2 particle2d::getPosition()
{
    return glm::vec2(x,y);
}

glm::vec2 particle2d::getSpeed()
{
    return glm::vec2(x,y);
}


particle2d::~particle2d()
{
    //dtor
}
