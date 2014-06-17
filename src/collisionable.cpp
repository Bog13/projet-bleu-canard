#include "collisionable.h"

void Collisionable::init()
{
    m_hitbox.x=0;
    m_hitbox.y=0;
    m_hitbox.w=0;
    m_hitbox.h=0;
}

Collisionable::Collisionable()
{
    init();
    m_solid=false;
}

Collisionable::Collisionable(bool solid)
{
    init();
    m_solid=solid;
}

void Collisionable::setHitbox(float x,float y,float w,float h)
{
    m_hitbox.x=x;
    m_hitbox.y=y;
    m_hitbox.w=w;
    m_hitbox.h=h;
}

void Collisionable::setHitbox(ConvexShape cs)
{
    RectangleShape *rs=0;
    rs=dynamic_cast<RectangleShape*>(&cs);

    if(rs!=0)
    {
        cout<<"OK- setHitbox"<<endl;
        m_hitbox.x=rs->getPosition().x;
        m_hitbox.y=rs->getPosition().y;
        m_hitbox.w=rs->getSize().x;
        m_hitbox.h=rs->getSize().y;
    }else cout<<"NOPE- setHitbox"<<endl;

}

Collisionable::~Collisionable()
{
    //dtor
}
