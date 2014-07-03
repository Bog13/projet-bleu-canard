#include "movable.h"

Movable::Movable(Collisionable *c, Positionable* p, pair<float,float> speed): m_positionable(p),m_collisionable(c),m_absoluteSpeed(speed)
{
    m_direction=RIGHT;
}

bool Movable::canMoveUp()
{
        int t=m_direction;
    moveUp(m_speed.second);
    bool b= m_positionable->getArea()->isAccessible(*this);
    moveDown(m_speed.second);
        m_direction=t;
    return  b;
}

bool Movable::canMoveDown()
{
        int t=m_direction;
    moveDown(m_speed.second);
    bool b= m_positionable->getArea()->isAccessible(*this);
    moveUp(m_speed.second);
        m_direction=t;
    return  b;
}

bool Movable::canMoveLeft()
{
        int t=m_direction;
    moveLeft(m_speed.first);
    bool b= m_positionable->getArea()->isAccessible(*this);
    moveRight(m_speed.first);
        m_direction=t;
    return  b;

}

bool Movable::canMoveRight()
{
        int t=m_direction;
    moveRight(m_speed.first);
    bool b= m_positionable->getArea()->isAccessible(*this);
    moveLeft(m_speed.first);
        m_direction=t;
    return  b;
}

void Movable::updateMovable()
{
    m_speed.first=m_absoluteSpeed.first / Global::FPS ;
    m_speed.second=m_absoluteSpeed.second / Global::FPS;
}

Movable::~Movable()
{

}
