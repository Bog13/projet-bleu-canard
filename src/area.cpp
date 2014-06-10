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



void Area::addTiles(int w, int h)
///Fonctionne parfaitement
{
    for(int i(0);i<m_tiles.size();i++)
    {
        for (int j(0);j<w;j++)
        {
            m_tiles[i].push_back(new Tile(Global::ID_GRASS));
        }
    }

    for(int i(0);i<h;i++)
    {
        vector<Tile*> temp;
        for (int j(0);j<=w;j++)
        {
            temp.push_back(new Tile(Global::ID_GRASS));
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
    }else cerr<<"Tentative d'acces � objects["<<i<<"] !"<<endl;
}

void Area::update()
{
    cout << " Area::update() inutile :p" << endl;
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
