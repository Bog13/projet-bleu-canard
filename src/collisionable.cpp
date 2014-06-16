#include "collisionable.h"

Collisionable::Collisionable()
{
    m_hitbox.x=0;
    m_hitbox.y=0;
    m_hitbox.w=0;
    m_hitbox.h=0;
    m_solid=false;
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
    m_hitbox.x=cs.getPosition().x;
    m_hitbox.y=cs.getPosition().y;
}

Collisionable::~Collisionable()
{
    //dtor
}
