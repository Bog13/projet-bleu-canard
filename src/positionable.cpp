#include "positionable.h"

Positionable::Positionable()
{
    Positionable(0,0);
}

Positionable::Positionable(pair<float,float> pos)
{
    m_position.first=pos.first;
    m_position.second=pos.second;

    m_width=0;
    m_height=0;
}

Positionable::Positionable(float x,float y,float w,float h)
{
    setPosition(x,y);
    m_width=w;
    m_height=h;


}

Positionable::Positionable(float x,float y)
{
    setPosition(x,y);
    m_width=0;
    m_height=0;

}

Positionable::~Positionable()
{
    //dtor
}
