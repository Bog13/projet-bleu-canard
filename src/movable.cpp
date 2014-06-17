#include "movable.h"

Movable::Movable(Positionable* p,pair<float,float> speed): m_positionable(p),m_speed(speed)
{
    //ctor
}

bool Movable::canMoveUp()
{
    Positionable p(0,m_positionable->getX(),m_positionable->getY()-m_speed.second,m_positionable->getWidth(),m_positionable->getHeight());
    return  m_positionable->getArea()->isAccessible(p);
}

bool Movable::canMoveDown()
{
    Positionable p(0,m_positionable->getX(),m_positionable->getY()+m_speed.second,m_positionable->getWidth(),m_positionable->getHeight());
    return  m_positionable->getArea()->isAccessible(p);
}

bool Movable::canMoveLeft()
{
    Positionable p(0,m_positionable->getX()-m_speed.first,m_positionable->getY(),m_positionable->getWidth(),m_positionable->getHeight());
    return  m_positionable->getArea()->isAccessible(p);
}

bool Movable::canMoveRight()
{
    Positionable p(0,m_positionable->getX()+m_speed.first,m_positionable->getY(),m_positionable->getWidth(),m_positionable->getHeight());
    return  m_positionable->getArea()->isAccessible(p);
}


Movable::~Movable()
{
    //dtor
}
