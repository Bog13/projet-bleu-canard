#include "object.h"

Object::Object():Tile(),Positionable(),Collisionable()
{
    m_width=0;
    m_height=0;
}

Object::Object(int type,float x, float y,float w,float h):Tile(type),Positionable(x,y,w,h),Collisionable()
{


}

void Object::update()
{
    Tile::update();
}

Object::Object(int type,float x, float y,float w,float h,bool obs):Tile(type),Positionable(x,y,w,h),Collisionable(obs)
{

}

Object::~Object()
{
    //dtor
}
