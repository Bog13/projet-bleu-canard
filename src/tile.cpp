#include "../include/tile.h"

Tile::Tile()
{
    m_id=-1;
    m_posX=m_posY=0;
}

Tile::Tile(int id,int x,int y)
{
    m_id=id;
    m_posX=m_posY=0;
}

Tile::Tile(int x,int y)
{
    m_id=-1;
    m_posX=x;
    m_posY=y;
}

Tile::~Tile()
{
    //dtor
}
