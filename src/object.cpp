#include "object.h"

Object::Object():Tile()
{
    m_width=0;
    m_height=0;
    m_x=0;
    m_y=0;
    m_isAnObstacle=false;
}

Object::Object(int type,float x, float y,float w,float h):Tile(type)
{
    m_width=w;
    m_height=h;
    m_x=x;
    m_y=y;
    m_isAnObstacle=false;
}

Object::Object(int type,float x, float y,float w,float h,bool obs):Tile(type)
{
    m_width=w;
    m_height=h;
    m_x=x;
    m_y=y;
    m_isAnObstacle=obs;
}

Object::~Object()
{
    //dtor
}
