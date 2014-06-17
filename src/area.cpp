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
            vecTile.push_back(new Tile(Global::ID[FLOOR_WOOD]));
        }

        m_tiles.push_back(vecTile);
    }

}



bool Area::isAccessible(Movable &pos)
{
    int nbCollide=0;

    float
    x=pos.getPos()->getX() + pos.getCol()->getHitbox().x,
    y=pos.getPos()->getY() + pos.getCol()->getHitbox().y,
    w=x  + pos.getCol()->getHitbox().w,
    h=y  + pos.getCol()->getHitbox().h;

    float obj_x,obj_y,obj_w,obj_h;

    for(int i=0;i<m_objects.size();i++)
    {
        obj_x=m_objects[i]->getX() + m_objects[i]->getHitbox().x;
        obj_y=m_objects[i]->getY() + m_objects[i]->getHitbox().y;
        obj_w= obj_x + m_objects[i]->getHitbox().w;
        obj_h= obj_y + m_objects[i]->getHitbox().h;

        if(  ( h < obj_y || y > obj_h || w < obj_x || x > obj_w)
             && x>=0 && w <=m_width*Global::TILE_WIDTH
             && y>=0 && h <=m_height*Global::TILE_HEIGHT
             && m_objects[i]->getSolid()
        )
        {

        }
        else
        {
            nbCollide++;
        }

        if(nbCollide>1)return false;
    }

    return !(nbCollide>1);
}

void Area::addTiles(int w, int h)
{
    for(int i(0);i<m_tiles.size();i++)
    {
        for (int j(0);j<w;j++)
        {
            m_tiles[i].push_back(new Tile(Global::ID[HIGHT_GRASS]));
        }
    }

    for(int i(0);i<h;i++)
    {
        vector<Tile*> temp;
        for (int j(0);j<=w;j++)
        {
            temp.push_back(new Tile(Global::ID[HIGHT_GRASS]));
        }
        m_tiles.push_back(temp);
    }
    m_width+=w;
    m_height+=h;
}

void Area::getInfo()
///Affiche le contenu d'une area.
{
    for(int i(0);i<m_tiles.size();i++)
    {
        for (int j(0);j<m_tiles[i].size();j++)
        {
            cout<<m_tiles[i][j]->getType();
        }
        cout<<endl;
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
    if(y>=0 && y<m_tiles.size() && x>=0 && x<m_tiles[y].size()) {return m_tiles[y][x];}
    else cerr<<"getTile hors normes (Area::getTile) indice x:" << x << " y:" << y <<"."<<endl;

}

Object* Area::getObject(int i)
{
    if(i>=0 && i<m_objects.size())
    {
        return m_objects[i];
    }else cerr<<"Tentative d'acces à objects["<<i<<"] !"<<endl;
}

void Area::updateTiles()
{
    for(int i=0;i<m_height;i++)
    {
        for(int j=0;j<m_width;j++)
        {
            m_tiles[i][j]->update();
        }
    }
}

void Area::updateObjects()
{
    for(int i=0;i<m_objects.size();i++)
    {
        m_objects[i]->update();

    }
}

void Area::update()
{
    updateTiles();
    updateObjects();
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

void Area::modifyTile(int x, int y, int tileID)
{
     if(y>=0 && y<m_tiles.size() && x>=0 && x<m_tiles[y].size()) {m_tiles[y][x]->setType(tileID);}
     else cerr<<"Tring to access a m_tiles[x][y] impossible [Area::modifyTile()]"<<endl;

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
