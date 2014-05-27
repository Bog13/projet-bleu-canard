#include "../include/area.h"

Area::Area()
{
    for(int i=0;i<Global::NB_TILE_HEIGHT;i++)
    {
       for(int j=0;j<Global::NB_TILE_WIDTH;j++)
       {
           m_tiles.push_back(new Tile(j,i));
       }
    }
}

Tile* Area::getTile(int x,int y)
{
    return m_tiles[x+Global::NB_TILE_WIDTH*y];
}



Area::~Area()
{
    for(int i=0;i<m_tiles.size();i++)
    {
        delete m_tiles[i];
    }

    for(int i=0;i<m_characters.size();i++)
    {
        delete m_characters[i];
    }

}
