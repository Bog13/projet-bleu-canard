#include "movable.h"

Movable::Movable(Collisionable *c, Positionable* p, pair<float,float> speed): m_positionable(p),m_collisionable(c),m_absoluteSpeed(speed)
{
    m_direction=RIGHT;
    m_isMoving=false;
}

bool Movable::canMoveUp()
{
    return !collide(0,-m_speed.second);

}

bool Movable::canMoveDown()
{
    return !collide(0,m_speed.second);

}

bool Movable::canMoveLeft()
{

    return !collide(-m_speed.first,0);


}

bool Movable::canMoveRight()
{

   return !collide(m_speed.first,0);

}
bool Movable::collide(float xt, float yt)
{
    return ( collideWithArea(xt,yt) || collideWithObjects(xt,yt) );
}

bool Movable::collideWithArea(float xt, float yt)
{
    float x=0,y=0,w=0,h=0;
    float xn=0,yn=0,wn=0,hn=0;

    x=m_collisionable->getHitbox().x+xt+m_positionable->getX();
    y=m_collisionable->getHitbox().y+yt+m_positionable->getY();
    w=m_collisionable->getHitbox().w;
    h=m_collisionable->getHitbox().h;


    return ( x< 0 || x + w >= m_positionable->getArea()->getWidth()* Global::TILE_WIDTH
    ||  y<0  || y + h >= m_positionable->getArea()->getHeight()* Global::TILE_HEIGHT);
}

bool Movable::collideWithObjects(float xt, float yt)
{
    Object* o=0;
    float x=0,y=0,w=0,h=0;
    float xn=0,yn=0,wn=0,hn=0;

    x=m_collisionable->getHitbox().x+xt+m_positionable->getX();
    y=m_collisionable->getHitbox().y+yt+m_positionable->getY();
    w=m_collisionable->getHitbox().w;
    h=m_collisionable->getHitbox().h;

    for(int i(0);i<m_positionable->getArea()->nbObject();i++)
    {
        o=m_positionable->getArea()->getObject(i);

        if( dynamic_cast<Movable*>(o) != this && m_positionable->getDistanceTo(o)< 5*Global::TILE_WIDTH)
        {

            xn= o->getHitbox().x + o->getX();
            yn= o->getHitbox().y + o->getY();
            wn= o->getHitbox().w;
            hn= o->getHitbox().h;

            ///Actualisation du statut "En collision" de l'objet.
            m_collisionable->setCollide(Global::inCollision(x,y,w,h,xn,yn,wn,hn));

            if(m_collisionable->isInCollision()){return true;}
        }
    }

    return false;
}

void Movable::updateMovable()
{
    m_speed.first=m_absoluteSpeed.first / Global::FPS ;
    m_speed.second=m_absoluteSpeed.second / Global::FPS;
    m_isMoving=false;






    ///
}

Movable::~Movable()
{

}
