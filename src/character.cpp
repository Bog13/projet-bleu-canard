#include "character.h"

Character::Character():Object()
{
    //ctor
}

Character::Character(int type,float x, float y,float w,float h):Object(type,x,y,w,h)
{
}

Character::~Character()
{
    //dtor
}
