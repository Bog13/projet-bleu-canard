#include "movable.h"

Movable::Movable(Collisionable *c, Positionable* p, pair<float,float> speed): m_positionable(p),m_speed(speed),m_collisionable(c)
{

}

bool Movable::canMoveUp()
{
    moveUp(m_speed.second);
    bool b= m_positionable->getArea()->isAccessible(*this);
    moveDown(m_speed.second);
    return  b;
}

bool Movable::canMoveDown()
{
    moveDown(m_speed.second);
    bool b= m_positionable->getArea()->isAccessible(*this);
    moveUp(m_speed.second);
    return  b;
}

bool Movable::canMoveLeft()
{
    moveLeft(m_speed.first);
    bool b= m_positionable->getArea()->isAccessible(*this);
    moveRight(m_speed.first);
    return  b;
}

bool Movable::canMoveRight()
{
    moveRight(m_speed.first);
    bool b= m_positionable->getArea()->isAccessible(*this);
    moveLeft(m_speed.first);
    return  b;
}


Movable::~Movable()
{

}
