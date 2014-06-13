#include "positionable.h"

Positionable::Positionable()
{
    Positionable(0,0);
}

Positionable::Positionable(pair<float,float> pos)
{
    m_position=pos;
}

Positionable::Positionable(float x,float y)
{
    m_position.first=x;
    m_position.second=y;
}

Positionable::~Positionable()
{
    //dtor
}
