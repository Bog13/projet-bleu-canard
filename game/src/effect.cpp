#include "effect.h"

//#include "tile.h"

Effect::Effect()
{
    m_target=0;
}

Effect::Effect(Tile* t)
{
    m_target=t;
}
void Effect::apply()
{

}

Effect::~Effect()
{
    //dtor
}
