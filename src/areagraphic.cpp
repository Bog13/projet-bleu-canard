#include "areagraphic.h"

AreaGraphic::AreaGraphic(Area *a)
{
    m_area=a;

    m_width=a->getWidth();
    m_height=a->getHeight();

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

            vecTile->push_back(TileFactory::get( m_area->getTile(j,i)->getType() ));

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
