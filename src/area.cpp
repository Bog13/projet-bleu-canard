#include "area.h"

Area::Area(int w,int h)
{
    m_width=w;
    m_height=h;
    initTile();

}

void Area::initTile()
{

    for(int i=0;i<m_height;i++)
    {
        vector<Tile*> vecTile;

        for(int j=0;j<m_width;j++)
        {
            vecTile.push_back(new Tile(Global::ID_GRASS));
        }

        m_tiles.push_back(vecTile);
    }

}

///OPTIMISATION POSSIBLE (cad sans tout reallouer)
/*void Area::addTiles(int w,int h)
{
    m_height+=h;
    m_width+=w;
    for(int i=0;i<h;i++)
    {
        vector<Tile*> vecTile;

        for(int j=0;j<w;j++)
        {
            vecTile.push_back(new Tile(Global::ID_GRASS));
        }

        m_tiles.push_back(vecTile);
    }
}

void Area::newSize(int w,int h)
{
    if(w>m_width && h>m_height)
    {
        addTiles(w-m_width, h-m_height);
    }
    else if(w==m_width && h==m_height){cerr<<"Warning: newSize inutile !"<<endl;}
    else if()

    for(int i=0;i<m_height;i++)
    {
        vector<Tile*> vecTile;

        for(int j=0;j<m_width;j++)
        {
            vecTile.push_back(new Tile(Global::ID_GRASS));
        }

        m_tiles.push_back(vecTile);
    }

}*/

void Area::newSize(int w,int h)
{
    killTiles();
    m_tiles=vector<vector<Tile*> >();

    m_height=h;
    m_width=w;
    initTile();
}

void Area::setTiles(vector<vector<int> > values)
{

    for(int i=0;i<m_height;i++)
    {

        for(int j=0;j<m_width;j++)
        {
            m_tiles[i][j]->setType(values[i][j]);
        }

    }

}

Tile* Area::getTile(int x,int y)
{
    return m_tiles[y][x];
}

Object* Area::getObject(int i)
{
    if(i>=0 && i<m_objects.size())
    {
        return m_objects[i];
    }else cerr<<"Tentative d'acces à objects["<<i<<"] !"<<endl;
}

void Area::update()
{

}

void Area::killTiles()
{
    for(int i=0;i<m_height;i++)
    {
        for(int j=0;j<m_width;j++)
        {
            delete m_tiles[i][j];
        }
    }
}

void Area::killObjects()
{
    for(int i=0;i<m_objects.size();i++)
    {
        delete m_objects[i];
    }
}

Area::~Area()
{
    killTiles();
    killObjects();
}
