#include "area.h"

Area::Area()
{
    initTile();
}

void Area::initTile()
{

    for(int i=0;i<m_height;i++)
    {
        vector<Tile*> vecTile;

        for(int j=0;j<m_width;j++)
        {
            vecTile.push_back(new Tile(Global::ID_NONE));
        }

        m_tiles.push_back(vecTile);
    }

}

Tile* Area::getTile(int x,int y)
{
    return m_tiles[y][x];
}

void Area::update()
{

}


Area::~Area()
{
    for(int i=0;i<m_height;i++)
    {
        for(int j=0;j<m_width;j++)
        {
            delete m_tiles[i][j];
        }
    }
}
