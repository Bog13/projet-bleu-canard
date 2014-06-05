#include "charactergraphic.h"

CharacterGraphic::CharacterGraphic(Animation a, ConvexShape cs)
{
    m_animation=a;//ctor
    m_convexShape=cs;
}


void CharacterGraphic::update()
{
    m_animation.update();

}

CharacterGraphic::~CharacterGraphic()
{
    //dtor
}
