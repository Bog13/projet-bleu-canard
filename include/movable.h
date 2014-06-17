#ifndef MOVABLE_H
#define MOVABLE_H

#include "positionable.h"
#include "area.h"
using namespace std;

class Movable
/**
    Permet à un positionnable de bouger.
    ATTENTION, la sécurité "Est-il dans l'area" est à insérer avant ces méthodes.
    ex: Positionnable::move(d)
    { if (isInArea==true) {moveLeft(d);}}
**/

{
    public:
        Movable(Positionable* p,pair<float,float> speed=pair<float,float>(1,1) );
        void addPosition(float x,float y){m_positionable->setPosition(m_positionable->getPosition().first+x,m_positionable->getPosition().second+y);}

        void moveRight(float d) {addPosition(d,0);}
        void moveLeft(float d) {addPosition(-d,0);}
        void moveDown(float d) {addPosition(0,d);}
        void moveUp(float d) {addPosition(0,-d);}

        bool canMoveRight();

        void moveRight() { if(canMoveRight()) moveRight(m_speed.first); }
        void moveLeft() { if(canMoveRight()) moveLeft(m_speed.first); }
        void moveDown() { if(canMoveRight()) moveDown(m_speed.second); }
        void moveUp() { if(canMoveRight()) moveUp(m_speed.second); }
        void move(float up, float right, float down, float left) {moveLeft(left); moveRight(right); moveDown(down); moveUp(up);}
        void move(float xRelativ, float yRelativ) {addPosition(xRelativ,yRelativ);}
        void move(pair<float,float> p){addPosition(p.first,p.second);}


        virtual ~Movable();
    protected:
        Positionable *m_positionable;
        pair<float,float> m_speed;
    private:
};

#endif // MOVABLE_H
