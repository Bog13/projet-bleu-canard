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
        Hitbox getHitbox(){return m_hitbox;}
        void setHitbox(float x,float y,float w,float h);
        void setHitbox(Hitbox hit){m_hitbox=hit;}
        void setHitbox(ConvexShape cs);
        void setSolid(bool b){m_solid=b;}
        bool getSolid(){return m_solid;}

        virtual ~Collisionable();
    protected:
        Hitbox m_hitbox;
        bool m_solid;
    private:
};

#endif // COLLISIONABLE_H
