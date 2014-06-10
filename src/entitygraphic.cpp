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

void EntityGraphic::init(Animation &a,ConvexShape &c)
{
    m_animation=a;
    m_convexShape=c;
    m_hasAnEntity=false;
}

EntityGraphic::EntityGraphic(Tile* t,Animation a,ConvexShape c)
{
    m_entity=t;
    m_hasAnEntity=true;
    init(a,c);
}


void EntityGraphic::newType(int type)
{
    if(hasAnEntity())
    {
        m_entity->setType(type);
        m_animation=AnimationFactory::get(m_entity->getType());
    }
}

void EntityGraphic::update()
{

    m_animation.update();
}




EntityGraphic::~EntityGraphic()
{
    //dtor
}
