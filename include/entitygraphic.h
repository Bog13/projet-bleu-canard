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
        void newType(int type);
        void setEntity(Tile* e){m_entity=e;m_hasAnEntity=true;}
        bool hasAnEntity(){return m_hasAnEntity;}
        void update();
        void setAnimation(Animation a){m_animation=a;}
        void setConvexShape(ConvexShape cs){m_convexShape=cs;}
        virtual ~EntityGraphic();


    protected:
        ConvexShape m_convexShape;
        Animation m_animation;
        Tile* m_entity;
        bool m_hasAnEntity;
    private:
};

#endif // TILEGRAPHIC_H
