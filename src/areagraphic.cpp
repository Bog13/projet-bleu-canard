#include "areagraphic.h"

AreaGraphic::AreaGraphic(Area *a)
{
    m_area=a;

    m_width=a->getWidth();
    m_height=a->getHeight();

    initTiles();
    initObjects();
}

void AreaGraphic::initObjects()
{

    for(int i=0;i<m_area->nbObject();i++)
    {
        EntityGraphic* eg=new EntityGraphic;
        Animation a;
        Object *o=m_area->getObject(i);

        a=AnimationFactory::get( o->getType() );

        eg->setConvexShape(Graphics::createSquare(o->getX(),o->getY(),o->getWidth(),o->getHeight() ));
        eg->setAnimation(a);
        eg->setEntity(m_area->getObject(i));

        m_objects.push_back(eg);




    }
}

void AreaGraphic::initTiles()
{
    vector<EntityGraphic*>* vecTile=0;
    EntityGraphic* eg=0;

    for(int i=0;i<m_height;i++)
    {
        vecTile=new vector<EntityGraphic*>;

        for(int j=0;j<m_width;j++)
        {
            eg=new EntityGraphic;
            *eg= TileFactory::get( m_area->getTile(j,i)->getType() );
            eg->setEntity(m_area->getTile(j,i));
            vecTile->push_back(eg);

        }

        m_tiles.push_back(*vecTile);
    }

    delete vecTile;

}

EntityGraphic* AreaGraphic::getTileGraphic(int x,int y)
{
    return m_tiles[y][x];
}

EntityGraphic* AreaGraphic::getObjectGraphic(int i)
{
    if(i>=0 && i<m_objects.size())
    {
        EntityGraphic *eg=m_objects[i];
        return eg;
    }else cerr<<"Tentative d'acces à objects["<<i<<"] !"<<endl;
}

void AreaGraphic::updateTiles()
{
    for(int i=0;i<m_height;i++)
    {
        for(int j=0;j<m_width;j++)
        {
            m_tiles[i][j]->update();
        }
    }
}

void AreaGraphic::updateObjects()
{
    for(int i=0;i<m_objects.size();i++)
    {
        m_objects[i]->update();

    }
}

void AreaGraphic::update()
{
    updateTiles();
    updateObjects();
}


AreaGraphic::~AreaGraphic()
{

}
