#include "area.h"

#include "tile.h"
#include "global.h"
#include "object.h"

Area::Area(int w,int h)
{
    m_tiles=vector<vector<Tile*> > ();
    m_objects=vector<Object* >();
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
            vecTile.push_back(new Tile(Global::ID[FLOOR_PAVEMENT])); ///Ici pour mettre la texture de base des tiles de l'area
        }

        m_tiles.push_back(vecTile);
    }

}

bool Area::isAccessible(Movable &pos)
{
    cout << " j'ai rien fait. " << endl;
    /*Positionable* o=dynamic_cast<Positionable*>(pos.getClosestNeighbor());
    if(o==0) {cout << " YO ! " <<endl; return true ;}
    else
    {
    return !(Global::inCollision(pos.getPos()->getX(),pos.getPos()->getY(),pos.getPos()->getWidth(),pos.getPos()->getHeight(),o->getX(),o->getY(),o->getWidth(),o->getHeight()));
    }*/

    //else return !(Global::inCollision(pos.getPos()->getX(),pos.getPos()->getY(),pos.getPos()->getWidth(),pos.getPos()->getHeight(),o->getX(),o->getX(),o->getWidth(),o->getHeight()));
    /*
    int nbCollide=0;

    float
    x=pos.getPos()->getX() + pos.getCol()->getHitbox().x,
    y=pos.getPos()->getY() + pos.getCol()->getHitbox().y,
    w=x  + pos.getCol()->getHitbox().w,
    h=y  + pos.getCol()->getHitbox().h;

    float obj_x,obj_y,obj_w,obj_h;

    /*for(int i=0;i<(int)(m_objects.size());i++) AVANT OPTI
    {
        obj_x=m_objects[i]->getX() + m_objects[i]->getHitbox().x;
        obj_y=m_objects[i]->getY() + m_objects[i]->getHitbox().y;
        obj_w= obj_x + m_objects[i]->getHitbox().w;
        obj_h= obj_y + m_objects[i]->getHitbox().h;


        if( !Global::inCollision(x,y,w,h,obj_x,obj_y,obj_w,obj_h)
             && x>=0 && w <=m_width*Global::TILE_WIDTH
             && y>=0 && h <=m_height*Global::TILE_HEIGHT
        )
        //pas de collision
        {

        }
        else
        {
            if(m_objects[i]->getSolid()==true) nbCollide++;
        }

        if(nbCollide>1)return false;
    }


        obj_x=pos.getClosestNeighbor()->getX() + pos.getClosestNeighbor()->getHitbox().x;
        obj_y=pos.getClosestNeighbor()->getY() + pos.getClosestNeighbor()->getHitbox().y;
        obj_w= obj_x + pos.getClosestNeighbor()->getHitbox().w;
        obj_h= obj_y + pos.getClosestNeighbor()->getHitbox().h;


        if( !Global::inCollision(x,y,w,h,obj_x,obj_y,obj_w,obj_h)
             && x>=0 && w <=m_width*Global::TILE_WIDTH
             && y>=0 && h <=m_height*Global::TILE_HEIGHT
        )
        //pas de collision
        {
            return true;
        }
        else
        {
            if(pos.getClosestNeighbor()->getSolid()==true) return false;

        }

        return true;
*/
}



void Area::addTiles(int w, int h)
{
    for(int i(0);i<(int)(m_tiles.size());i++)
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

bool Area::modifyTile(int x, int y, int id)
{
    bool tmp=in(x,y) && id<=Global::NB_TOTAL_ID && id>=0;
    if(tmp)
    {
        m_tiles[y][x]->setType(id);
    }
    return tmp;
}

void Area::getInfo()
///Affiche le contenu d'une area.
{
    for(int i(0);i<(int)(m_tiles.size());i++)
    {
        for (int j(0);j<(int)(m_tiles[i].size());j++)
        {
            cout<<m_tiles[i][j]->getType();
        }
        cout<<endl;
    }
}

void Area::addObject(Object* o, float x, float y)
{
    o->setPosition(x,y);
    m_objects.push_back(o);
}


void Area::newSize(int w,int h)
{
    killTiles();
    //m_tiles=vector<vector<Tile*> >();
    m_tiles.erase(m_tiles.begin(),m_tiles.end());

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
    if(y>=0 && y<(int)(m_tiles.size()) && x>=0 && x<(int)(m_tiles[y].size())) {return m_tiles[y][x];}
    else {cerr<<"getTile hors normes (Area::getTile) indice x:" << x << " y:" << y <<"."<<endl;return 0;}

}

Object* Area::getObject(int i)
{
    if(i>=0 && i<(int)(m_objects.size()))
    {
        return m_objects[i];
    }else {cerr<<"Tentative d'acces � objects["<<i<<"] !"<<endl; return 0;}
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
    for(int i=0;i<(int)(m_objects.size());i++)
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


void Area::killObjects()
{
    for(int i=0;i<(int)(m_objects.size());i++)
    {
        delete m_objects[i];
    }
}

Area::~Area()
{
    killObjects();
    killTiles();

}
