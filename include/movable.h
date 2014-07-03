#ifndef MOVABLE_H
#define MOVABLE_H
#include "collisionable.h"
#include "positionable.h"
#include "area.h"
#include "object.h"
using namespace std;

class Core;
class Object;

class Movable
/**
    Permet à un positionnable de bouger.

**/

{
    public:
        Movable(Collisionable *c,Positionable* p, pair<float,float> speed=pair<float,float>(1,1) );
        void addPosition(float x,float y){m_positionable->setPosition(m_positionable->getPosition().first+x,m_positionable->getPosition().second+y);}

        void goRight(float d) {addPosition(d,0);}
        void goLeft(float d) {addPosition(-d,0);}
        void goDown(float d) {addPosition(0,d);}
        void goUp(float d) {addPosition(0,-d);}

        bool canMoveUp();
        bool canMoveDown();
        bool canMoveLeft();
        bool canMoveRight();

        void moveRight() { if(canMoveRight()){m_direction=RIGHT; goRight(m_speed.first); }}
        void moveLeft() { if(canMoveLeft()) {m_direction=LEFT;goLeft(m_speed.first); }}
        void moveDown() { if(canMoveDown()) {m_direction=DOWN;goDown(m_speed.second); }}
        void moveUp() { if(canMoveUp()) {m_direction=UP;goUp(m_speed.second); }}

        /*void move(float up, float right, float down, float left) {moveLeft(left); moveRight(right); moveDown(down); moveUp(up);}
        void move(float xRelativ, float yRelativ) {addPosition(xRelativ,yRelativ);}
        void move(pair<float,float> p){addPosition(p.first,p.second);}*/


        void setSpeed(float x,float y){m_speed=pair<float,float>(x,y);}
        void setDirection(int val) {if(val<4)m_direction=val;}

        pair<float,float> getSpeed(){return m_absoluteSpeed;}
        Positionable* getPos(){return m_positionable;}
        Collisionable* getCol(){return m_collisionable;}
        int getDirection() {return m_direction;}
        const Object * getClosestNeighbor() {return m_closestNeighbor;}


        bool collideWithObjects(float x, float y);
        bool collideWithArea(float x, float y);
        bool collide(float x, float y);


        void updateCloserNeighbor();
        void updateMovable();

        virtual ~Movable();
    protected:
        Positionable *m_positionable;
        Collisionable *m_collisionable;
        pair<float,float> m_speed;
        pair<float,float> m_absoluteSpeed; //Warning
        int m_direction; //Sert à l'animation et à la position de la vue

        const Object * m_closestNeighbor;
    private:
};

#endif // MOVABLE_H
