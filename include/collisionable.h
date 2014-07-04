#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

struct Hitbox
{
    float x;
    float y;
    float w;
    float h;
};

class Collisionable
{
    public:
        Collisionable(bool b);
        Collisionable(float x,float y,float w,float h,bool b=false);
        Collisionable();
        void init();
        Hitbox getHitbox() const {return m_hitbox;}
        void setHitbox(float x,float y,float w,float h);
        void setHitbox(Hitbox hit){m_hitbox=hit;}
        void setHitbox(ConvexShape cs);
        void setSolid(bool b){m_solid=b;}
        bool getSolid(){return m_solid;}

        bool isInCollision() {return m_inCollisionWithObject;}
        void setCollide(bool b=true) {m_inCollisionWithObject=b;}

        virtual ~Collisionable();
    protected:
        Hitbox m_hitbox;
        bool m_solid;
        bool m_inCollisionWithObject; ///ATTENTION ! Ne prend pas en compte une collision avec le bord de l'area, car pas une vraie collision
    private:
};

#endif // COLLISIONABLE_H
