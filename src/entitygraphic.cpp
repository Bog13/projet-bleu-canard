#include "entitygraphic.h"

EntityGraphic::EntityGraphic(Animation a,ConvexShape c)
{
    m_entity=0;
    init(a,c);

}

EntityGraphic::EntityGraphic()
{
    m_entity=0;
    m_hasAnEntity=false;
}

Positionable* EntityGraphic::getPosition()
{
    if(!m_hasAnEntity)return 0;

    Positionable* pos=0;
    pos=dynamic_cast<Positionable*>(m_entity);
    return pos;
}

void EntityGraphic::init(Animation &a,ConvexShape &c)
{
    m_animation=a;
    m_convexShape=c;
    m_hasAnEntity=false;

    //obligatoire pour l'affichage
    m_visible=false;
}

EntityGraphic::EntityGraphic(Tile* t,Animation a,ConvexShape c)
{
    m_entity=t;
    m_hasAnEntity=true;
    init(a,c);
}


void EntityGraphic::setGraphicalType(int type)
{
    if(hasAnEntity())
    {
        m_animation=AnimationFactory::get(m_entity->getType());
    }
}

void EntityGraphic::update()
{
    m_animation.update();
}

void EntityGraphic::synchronise(int f)
{
    m_animation.setCurrentFrame(f);
}




EntityGraphic::~EntityGraphic()
{
    //dtor
}
