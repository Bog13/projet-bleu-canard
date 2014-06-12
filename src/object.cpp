#include "object.h"

Object::Object():Tile(),Positionable()
{
    m_width=0;
    m_height=0;
    m_isAnObstacle=false;
}

Object::Object(int type,float x, float y,float w,float h):Tile(type),Positionable(x,y)
{
    m_width=w;
    m_height=h;
    m_isAnObstacle=false;
}

Object::Object(int type,float x, float y,float w,float h,bool obs):Tile(type),Positionable(x,y)
{
    m_width=w;
    m_height=h;

    m_isAnObstacle=obs;
}

Object::~Object()
{
    //dtor
}
