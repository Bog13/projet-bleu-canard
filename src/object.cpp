#include "object.h"

Object::Object(Area *a):Tile(),Positionable(a),Collisionable()
{
    m_width=0;
    m_height=0;
}

Object::Object(Area *a, int type,float x, float y,float w,float h):Tile(type),Positionable(a,x,y,w,h),Collisionable(0,0,w,h)
{

}

void Object::update()
{
    Tile::update();
}



Object::Object(Area *a, int type,float x, float y,float w,float h,bool obs):Tile(type),Positionable(a,x,y,w,h),Collisionable(0,0,w,h,obs)
{

}

void Object::operator <<  (std::ostream& os) const
{
cout    << " _________OBJECT DEFINITION _________" << endl
        << " Type: " << m_type << endl
        << "Position: " << endl
        << "    " << " x = " << getX() << "  y = " << getY() << endl
        << "Size: " << endl
        << "    " << " w = " << getSize().x << " h = " << getSize().y << endl
        << "HitBox:" << endl
        << "    " << " x = " << getHitbox().x << " y = " << getHitbox().y <<" w = " << getHitbox().w << " h = " << getHitbox().h << endl
        << " __________END_______________________" << endl << endl;
}

void Object::collide(Object* o)
{
    for(unsigned int i(0);i<m_parameters.size();i++){m_parameters[i]->apply();}
}

void Object::operator=(Object o)
{
    *this=o;
    setPosition(o.getPosition());
}

Object::~Object()
{
    //dtor
}
