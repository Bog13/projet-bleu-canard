#include "movable.h"

Movable::Movable(Positionable* p,pair<float,float> speed): m_positionable(p),m_speed(speed)
{
    //ctor
}

bool Movable::canMoveRight()
{
   //return m_currentArea->isAccessible(m_positionable,new Positionable(m_positionable->getX(),m_positionable->getY(),2*m_speed.first,2*m_speed.second) );
}

Movable::~Movable()
{
    //dtor
}
