#ifndef TILEGRAPHIC_H
#define TILEGRAPHIC_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "animation.h"
#include "animationfactory.h"
#include "tile.h"
#include "object.h"
using namespace std;
using namespace sf;



class EntityGraphic
{
    public:
        EntityGraphic();///pour construire plus tard (pas très bien)
        EntityGraphic(Tile* t,Animation a,ConvexShape c);///utilisation normale
        EntityGraphic(Animation a,ConvexShape c);///non rattaché à un objet physique- sorte de modèle (ex: TileFactory n'est
                                                ///                                                   pas attaché à un objet précis)
        void init(Animation &a,ConvexShape &c);

        Animation* getAnimation(){return &m_animation;}
        ConvexShape* getConvexShape(){return &m_convexShape;}
        Tile* getEntity(){return m_entity;}
        void setGraphicalType(int type);
        void setEntity(Tile* e){m_entity=e;m_hasAnEntity=true;}
        bool hasAnEntity(){return m_hasAnEntity;}
        void update();
        void synchronise(int f);
        void setAnimation(Animation a){m_animation=a;}
        void setConvexShape(ConvexShape cs){m_convexShape=cs;}

        void setVisibility(bool b){m_visible=b;}
        bool isVisible(){return m_visible;}

        virtual ~EntityGraphic();

        void operator=(EntityGraphic *e)
        {
            e= this;
            if(m_entity!=0)e->m_entity=new Tile(*m_entity);
            else e->m_entity=0;
        }

    protected:


        ConvexShape m_convexShape;
        Animation m_animation;
        Tile* m_entity;
        bool m_hasAnEntity;
        bool m_visible;
    private:
};

#endif // TILEGRAPHIC_H
