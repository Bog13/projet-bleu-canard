#ifndef MOVABLE_H
#define MOVABLE_H
#include "collisionable.h"
#include "positionable.h"
#include "area.h"

using namespace std;

class Core;

class Movable
/**
    Permet à un positionnable de bouger.
    ATTENTION, la sécurité "Est-il dans l'area" est à insérer avant ces méthodes.
    ex: Positionnable::move(d)
    { if (isInArea==true) {moveLeft(d);}}
**/

{
    public:
        Movable(Collisionable *c,Positionable* p, pair<float,float> speed=pair<float,float>(1,1) );
        void addPosition(float x,float y){m_positionable->setPosition(m_positionable->getPosition().first+x,m_positionable->getPosition().second+y);}

        void moveRight(float d) {addPosition(d,0);}
        void moveLeft(float d) {addPosition(-d,0);}
        void moveDown(float d) {addPosition(0,d);}
        void moveUp(float d) {addPosition(0,-d);}

        bool canMoveUp();
        bool canMoveDown();
        bool canMoveLeft();
        bool canMoveRight();

        void moveRight() { if(canMoveRight()) moveRight(m_speed.first); }
        void moveLeft() { if(canMoveLeft()) moveLeft(m_speed.first); }
        void moveDown() { if(canMoveDown()) moveDown(m_speed.second); }
        void moveUp() { if(canMoveUp()) moveUp(m_speed.second); }
        void move(float up, float right, float down, float left) {moveLeft(left); moveRight(right); moveDown(down); moveUp(up);}
        void move(float xRelativ, float yRelativ) {addPosition(xRelativ,yRelativ);}
        void move(pair<float,float> p){addPosition(p.first,p.second);}

        pair<float,float> getSpeed(){return m_absoluteSpeed;}
        void setSpeed(float x,float y){m_speed=pair<float,float>(x,y);}
        Positionable* getPos(){return m_positionable;}
        Collisionable* getCol(){return m_collisionable;}
        void updateMovable();

        virtual ~Movable();
    protected:
        Positionable *m_positionable;
        Collisionable *m_collisionable;
        pair<float,float> m_speed;
        pair<float,float> m_absoluteSpeed; //Warning
    private:
};

#endif // MOVABLE_H
