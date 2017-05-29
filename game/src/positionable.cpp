#include "positionable.h"

Positionable::Positionable(Area *a)
{
    Positionable(a,0,0);
}

Positionable::Positionable(Area *a,pair<float,float> pos):m_currentArea(a)
{
    m_position.first=pos.first;
    m_position.second=pos.second;

    m_width=0;
    m_height=0;
}

Positionable::Positionable(Area *a,float x,float y,float w,float h):m_currentArea(a)
{
    setPosition(x,y);
    m_width=w;
    m_height=h;


}

int Positionable::getDistanceTo (const Positionable* pos) const
{
    return abs(pos->m_position.first-m_position.first) + abs(pos->m_position.second-m_position.second);
}

bool Positionable::collideWith(float x,float y,float w,float h)
{
    return Global::inCollision(m_position.first,m_position.second,m_width,m_height,x,y,w,h);
}

Positionable::Positionable(Area *a,float x,float y):m_currentArea(a)
{
    setPosition(x,y);
    m_width=0;
    m_height=0;

}

Positionable::~Positionable()
{
    //dtor
}
