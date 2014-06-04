#include "areagraphic.h"

AreaGraphic::AreaGraphic(int w,int h)
{

    m_width=w;
    m_height=h;

    initTile();
}


void AreaGraphic::initTile()
{
    vector<TileGraphic>* vecTile=0;
    for(int i=0;i<m_height;i++)
    {
        vecTile=new  vector<TileGraphic>;

        for(int j=0;j<m_width;j++)
        {

            vecTile->push_back(TileFactory::get(Global::ID_GRASS));

        }

        m_tiles.push_back(*vecTile);
    }

    delete vecTile;

}

TileGraphic* AreaGraphic::getTileGraphic(int x,int y)
{
    return &m_tiles[y][x];
}

void AreaGraphic::update()
{
    for(int i=0;i<m_height;i++)
    {
        for(int j=0;j<m_width;j++)
        {
            m_tiles[i][j].update();
        }
    }
}


AreaGraphic::~AreaGraphic()
{

}
