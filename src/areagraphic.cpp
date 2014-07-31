#include "areagraphic.h"

#include "tile.h"
#include "object.h"
#include "global.h"
#include "entitygraphic.h"
#include "tilefactory.h"
#include "animationfactory.h"
#include "area.h"
#include "camera.h"
#include "graphics.h"
#include "movable.h"

AreaGraphic::AreaGraphic(Area *a,Graphics* g):m_graphic(g),m_area(a)
{

    m_width=a->getWidth();
    m_height=a->getHeight();


    initTiles();
    initObjects();

    initSortObj();
    m_mustResort=false;

    if(g!=0) g->setAreaGraphic(this);
}
int AreaGraphic::nbObject()
    {
        return m_area->nbObject();
    }

void AreaGraphic::initSortObj()
{
    EntityGraphic* tmp=new EntityGraphic();
    int lowest=INT_MAX;

    for(unsigned int i=nbObject()-1;i>0;--i)
    {
        lowest= lowestObj(i);

        if( lowest != i)
        {
            *tmp=*m_objects[lowest];
            *m_objects[lowest] = *m_objects[i];
            *m_objects[i] = *tmp;
        }

        /*Global::clearConsole();
        cout<<"OBJECTS SORTING: "<<endl;
        cout<<"\t"<<Global::loadingString( nbObject()-1-i,nbObject());*/


    }
}

int AreaGraphic::lowestObj(int maxIndex)
//indice du plus bas
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

    //cout<<" I start sorting" << Global::random(0,500)<<endl; //Pour surveiller quand ca tri
    do
    {
        nb++;
        permut=false;

        for(int j=0;j<(int)(m_visibleObjects.size()-1);j++)
        {
            o1=dynamic_cast<Object*>(m_visibleObjects[j]->getEntity());
            if(o1!=0){hy1=o1->getHitbox().y;}
            else hy1=0;

            o2=dynamic_cast<Object*>(m_visibleObjects[j+1]->getEntity());
            if(o2!=0){hy2=o2->getHitbox().y;}
            else hy2=0;

            if(m_visibleObjects[j]->getConvexShape()->getPosition().y +hy1  >  m_visibleObjects[j+1]->getConvexShape()->getPosition().y+ hy2 )
            {
                tmp= *m_visibleObjects[j];
                *m_visibleObjects[j] = *m_visibleObjects[j+1];
                *m_visibleObjects[j+1]=tmp;
                permut=true;
            }

            remain--;

        }

    }
    while(permut && (nb < (int)(m_visibleObjects.size()-1)));
    //cout<<" I finished" <<endl; //idem qu'au-dessus
    setResortNecessity(false); ///Après le tri, plus besoin de trier


}

void AreaGraphic::initObjects()
{

    for(int i=0;i<m_area->nbObject();i++)
    {

                ///On prépare l'entité stoquée
                EntityGraphic* eg=new EntityGraphic;
                Animation a;
                ///On récupère l'objet i
                Object *o=m_area->getObject(i);
                a=AnimationFactory::get( o->getType() );


                ///Si c'est un arbre on décale aléatoirement
                if(o->getType()==PINE_TREE)a.setCurrentFrame(Global::random(0,Global::NB_FRAME_ID[PINE_TREE]));

                ///On crée un shape animé avec le bon ID
                eg->setConvexShape(Graphics::createSquare(o->getX(),o->getY(),o->getWidth(),o->getHeight() ));
                eg->setAnimation(a);
                eg->setEntity(m_area->getObject(i));

                ///On l'ajoute aux autres objets
                m_objects.push_back(eg);

        ///Affichage du chargement

        /*cout<<"OBJECTS: "<<endl;
        cout<<"\t"<<Global::loadingString( i,m_area->nbObject()-1);
        Global::clearConsole();*/
        ///
    }
}

void AreaGraphic::initTiles()
{
    vector<EntityGraphic*>* vecTile=0;
    EntityGraphic* eg=0;

    const int nbTiles=m_height*m_width;
    int nbTileDone=0;

    for(int i=0;i<m_height;i++)
    {
        vecTile=new vector<EntityGraphic*>;

        for(int j=0;j<m_width;j++)
        {
            eg=new EntityGraphic;
            *eg= TileFactory::get( m_area->getTile(j,i)->getType() );
            eg->setEntity(m_area->getTile(j,i));
            vecTile->push_back(eg);
            nbTileDone++;

        }

        m_tiles.push_back(*vecTile);

        /*Global::clearConsole();
        cout<<"TILES: "<<endl;
        cout<<"\t"<<Global::loadingString(nbTileDone,nbTiles);*/



    }

    delete vecTile;

}

EntityGraphic* AreaGraphic::getTileGraphic(int x,int y)
{
    if(y>=0 && y<(int)(m_tiles.size()) && x>=0 && x<(int)(m_tiles[y].size())) {return m_tiles[y][x];}
    else {cerr<<"getTile hors normes (Area::getTile) indice x:" << x << " y:" << y <<"."<<endl; return 0;}
}

EntityGraphic* AreaGraphic::getObjectGraphic(int i)
{
    if(i>=0 && i<(int)(m_objects.size()))
    {
        EntityGraphic *eg=m_objects[i];
        return eg;
    }else {cerr<<"Tentative d'acces à objects["<<i<<"] !"<<endl;return 0;}
}

EntityGraphic* AreaGraphic::getVisibleObjectGraphic(int i)
{
    if(i>=0 && i<(int)(m_visibleObjects.size()))
    {
        EntityGraphic *eg=m_visibleObjects[i];
        return eg;
    }else {cerr<<"Tentative d'acces à objects["<<i<<"] !"<<endl;return 0;}
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

void AreaGraphic::updateTiles(int i,int j)
{
    m_tiles[i][j]->update();

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
void AreaGraphic::updateVisibleObject(unsigned int i)
{
    if( m_objects[i]->hasAnEntity () )

        {
            Positionable* o=
             Global::convertInto<Tile*,Positionable*>(m_objects[i]->getEntity());

            Movable* m=Global::convertInto<Positionable*,Movable*>(o);

            if( o !=0 && m_graphic->getCamera() !=0)
            ///Si l'objet i existe et si la camera existe
            {

                if( m_graphic->getCamera()->inView( o )  )
                ///si l'objet est déjà dans la vue on ajoute
                {
                    m_objects[i]->setVisibility( true );
                    m_visibleObjects.push_back( m_objects[i] );

                }
                else if (o !=0 && m!=0 && m->isMoving() && m_graphic->getCamera()->inView(m)  )
                ///Ou si c'est un mouvable qui est dans la vue
                  {
                        m_objects[i]->setVisibility( true );
                        m_visibleObjects.push_back( m_objects[i] );
                   }



                else
                ///SINON c'est dehors
                {
                    m_objects[i]->setVisibility( false );
                }
            }else cout<<"Erreur: adr o= "<<o<<". (ag::updateObjects())"<<endl;

        }
}

void AreaGraphic::updateObjects()
{

    for(int i=0;i<(int)(m_objects.size());i++)
    {

        m_objects[i]->update();

        //update animation
        if(m_objects[i]->getAnimation()->getType() != m_objects[i]->getEntity()->getType())
        {
            m_objects[i]->setAnimation( AnimationFactory::get( m_objects[i]->getEntity()->getType()));
        }

        //update visible

        if(m_graphic->getCamera()->wasMoving() )
        {
            if(i==0)m_visibleObjects.erase(m_visibleObjects.begin(),m_visibleObjects.end());
            updateVisibleObject(i);
        }

        //update tri
        ///Si l'objet i est dans la zone et bouge à la vertical on tri.
        Movable* m=Global::convertInto<Tile*,Movable*>(m_objects[i]->getEntity());
        if(m!=0 && m->isMovingVertical() && m_graphic->getCamera()->inView(m)){setResortNecessity(true);}




    }


}


const void AreaGraphic::getInfo()
{
    for (int i(0);i<(int)(m_tiles.size());i++)
    {
        for (int j(0); j<(int)(m_tiles[i].size());j++)
        {
            cout<<m_tiles[i][j]->getEntity()->getType();
        }
        cout <<endl;
    }
}

void AreaGraphic::update()
{
    // Le Graphics s'en charge //updateTiles();
    updateObjects();
}


AreaGraphic::~AreaGraphic()
{

}
