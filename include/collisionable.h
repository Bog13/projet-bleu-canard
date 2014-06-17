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
        Collisionable(bool);
        Collisionable();
        void init();
        Hitbox getHitbox(){return m_hitbox;}
        inline void setHitbox(float x,float y,float w,float h);
        void setHitbox(Hitbox hit){m_hitbox=hit;}
        inline void setHitbox(ConvexShape cs);
        void setSolid(bool b){m_solid=b;}
        bool getSolid(){return m_solid;}

        virtual ~Collisionable();
    protected:
        Hitbox m_hitbox;
        bool m_solid;
    private:
};

#endif // COLLISIONABLE_H
