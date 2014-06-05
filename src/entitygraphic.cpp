#include "entitygraphic.h"

EntityGraphic::EntityGraphic(Animation a,ConvexShape c)
{
    m_animation=a;
    m_convexShape=c;
}

void EntityGraphic::update()
{
    m_animation.update();
}

EntityGraphic::EntityGraphic()
{

}


EntityGraphic::~EntityGraphic()
{
    //dtor
}
