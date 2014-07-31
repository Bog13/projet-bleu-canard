#include "teleport.h"

#include "tile.h"
#include "positionable.h"

Teleport::Teleport()
{
    m_target=0;
    m_xt=0;
    m_yt=0;
}

 Teleport::Teleport(Tile* t, float x, float y)
 {
     m_target=t;
     m_xt=x;
     m_yt=y;

 }


void Teleport::apply()
{
    Positionable* tileTemp=Global::convertInto<Tile*,Positionable*>(m_target);
    if(tileTemp!=0)tileTemp->setPosition(m_xt,m_yt);
}

Teleport::~Teleport()
{
    //dtor
}
