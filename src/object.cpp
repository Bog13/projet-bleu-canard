#include "object.h"

Object::Object(Area *a):Tile(),Positionable(a),Collisionable()
{
    m_width=0;
    m_height=0;
}

Object::Object(Area *a, int type,float x, float y,float w,float h):Tile(type),Positionable(a,x,y,w,h),Collisionable()
{


}

void Object::update()
{
    Tile::update();
}

Object::Object(Area *a, int type,float x, float y,float w,float h,bool obs):Tile(type),Positionable(a,x,y,w,h),Collisionable(obs)
{

}

Object::~Object()
{
    //dtor
}
