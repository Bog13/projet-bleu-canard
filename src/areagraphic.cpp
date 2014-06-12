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
    if(y>=0 && y<m_tiles.size() && x>=0 && x<m_tiles[y].size()) {return m_tiles[y][x];}
    else cerr<<"getTile hors normes (Area::getTile) indice x:" << x << " y:" << y <<"."<<endl;
}

EntityGraphic* AreaGraphic::getObjectGraphic(int i)
{
    if(i>=0 && i<m_objects.size())
    {
        EntityGraphic *eg=m_objects[i];
        return eg;
    }else cerr<<"Tentative d'acces à objects["<<i<<"] !"<<endl;
}

void AreaGraphic::verifyTiles()
/**
    Cette méthode était vide avant. Maintenant elle vérifie que les tiles de l'area membre (pouvant être modifiée)
    correspond à la copie en tilegraphics.
    Si oui, tout va bien.
    Si non, elle modifie l'animation de la tile graphics défaillante (modifiant alors son visuel)
    Pour cela, elle controle simplement les ID des tuiles (tile.getType() comparé à m_tiles[i][j]).
**/
{
    for(int i=0;i<m_height;i++)
    {
        for(int j=0;j<m_width;j++)
        {

            //GET INFO: cout <<"i= " << i << " j= " <<j << " type = " << m_area->getTile(j,i)->getType() << " type2 = "<< m_tiles[i][j]->getEntity()->getType() << endl;
            if( *(m_tiles[j][i]->getAnimation()) != AnimationFactory::get(m_area->getTile(j,i)->getType()) ) /// comparaison des animation entre area membre et m_tiles
               {
                   Animation a=AnimationFactory::get(m_area->getTile(j,i)->getType());
                   m_tiles[i][j]->setAnimation(a);                                      ///changement d'anim donc apparence



                }
        }
    }
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


const void AreaGraphic::getInfo()
{
    for (int i(0);i<m_tiles.size();i++)
    {
        for (int j(0); j<m_tiles[i].size();j++)
        {
            cout<<m_tiles[i][j]->getEntity()->getType();
        }
        cout <<endl;
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
