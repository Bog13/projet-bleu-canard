#include "tilegraphic.h"

TileGraphic::TileGraphic(Animation a,ConvexShape c)
{
    m_animation=a;
    m_convexShape=c;
}

void TileGraphic::update()
{
    m_animation.update();
}

TileGraphic::TileGraphic()
{

}


TileGraphic::~TileGraphic()
{
    //dtor
}
