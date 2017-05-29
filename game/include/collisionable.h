#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>

//#include "effect.h"

using namespace std;
using namespace sf;

class Object;
class Effect;

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

        void addEffect(Effect* e);
        Effect* getEffect(int n) {if(n<m_parameters.size() && n>=0)return m_parameters[n];}
        int getNumberOfEffect(){return m_parameters.size();}

        bool isInCollision() {return m_inCollisionWithObject;}
        void setCollide(bool b=true) {m_inCollisionWithObject=b;}
        void collide(Object* o);

        virtual ~Collisionable();
    protected:
        Hitbox m_hitbox;
        bool m_solid;
        bool m_inCollisionWithObject; ///ATTENTION ! Ne prend pas en compte une collision avec le bord de l'area, car pas une vraie collision
        vector<Effect*> m_parameters;
    private:
};

#endif // COLLISIONABLE_H
