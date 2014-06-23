#include "areagraphic.h"

AreaGraphic::AreaGraphic(Area *a)
{
    m_area=a;

    m_width=a->getWidth();
    m_height=a->getHeight();

    initTiles();
    initObjects();
}

int AreaGraphic::lowestObj(int maxIndex)
{
    int mini=0;

    for(int i=0;i<maxIndex;i++)
    {
        if(m_objects[i]->getConvexShape()->getPosition().y > m_objects[mini]->getConvexShape()->getPosition().y)
        {
            mini=i;
        }
    }
    return mini;
}

void AreaGraphic::sortObj()
///tri à bulle optimisé
{
    EntityGraphic tmp;
    bool permut;
    int nb=0;
    int remain=m_objects.size()-1;

    Object* o1= 0;
    int hy1 =0;

    Object* o2= 0;
    int hy2 =0;


    do
    {
        nb++;
        permut=false;

        for(int j=0;j<m_objects.size()-1;j++)
        {
            if(m_objects[j]->isVisible())
            //On se moque des objets invisibles
            {
                o1=dynamic_cast<Object*>(m_objects[j]->getEntity());
                if(o1!=0){hy1=o1->getHitbox().y;}
                else hy1=0;

                o2=dynamic_cast<Object*>(m_objects[j+1]->getEntity());
                if(o2!=0){hy2=o2->getHitbox().y;}
                else hy2=0;

                if(m_objects[j]->getConvexShape()->getPosition().y +hy1  >  m_objects[j+1]->getConvexShape()->getPosition().y+ hy2 )
                {
                    tmp= *m_objects[j];
                    *m_objects[j] = *m_objects[j+1];
                    *m_objects[j+1]=tmp;
                    permut=true;
                }

                remain--;
            }

        }

    }
    while(permut && (nb < m_objects.size()-1));




}

void AreaGraphic::initObjects()
{

    for(int i=0;i<m_area->nbObject();i++)
    {
        EntityGraphic* eg=new EntityGraphic;
        Animation a;
        Object *o=m_area->getObject(i);

        a=AnimationFactory::get( o->getType() );

        if(o->getType()==PINE_TREE)a.setCurrentFrame(Global::random(0,Global::NB_FRAME_ID[PINE_TREE]));
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

void AreaGraphic::synchroniseTiles(int f)
{
    Clock c;
    int frame=f;
    c.restart();
    for(int i=0;i<m_height;i++)
    {
        for(int j=0;j<m_width;j++)
        {
            if(c.getElapsedTime().asMilliseconds()>=m_tiles[i][j]->getAnimation()->getDelay() )
            {
                frame+= static_cast<int>( c.getElapsedTime().asMilliseconds()/m_tiles[i][j]->getAnimation()->getDelay());
                //c.restart();
            }
             m_tiles[i][j]->getAnimation()->setCurrentFrame(frame);
        }
    }


}

void AreaGraphic::updateObjects()
{
    for(int i=0;i<m_objects.size();i++)
    {
        m_objects[i]->update();

        if(m_objects[i]->getAnimation()->getType() != m_objects[i]->getEntity()->getType())
        {
            m_objects[i]->setAnimation( AnimationFactory::get( m_objects[i]->getEntity()->getType()));
        }
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
