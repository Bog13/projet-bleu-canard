#ifndef MOVABLE_H
#define MOVABLE_H

#include "positionable.h"

using namespace std;

class Movable: public Positionable
/**
    Permet à un positionnable de bouger.
    ATTENTION, la sécurité "Est-il dans l'area" est à insérer avant ces méthodes.
    ex: Positionnable::move(d)
    { if (isInArea==true) {moveLeft(d);}}
**/

{
    public:
        Movable();
        void moveRight(float d) {m_position.first+=d;}
        void moveLeft(float d) {m_position.first-=d;}
        void moveDown(float d) {m_position.second+=d;}
        void moveUp(float d) {m_position.second-=d;}
        void move(float up, float right, float down, float left) {moveLeft(left); moveRight(right); moveDown(down); moveUp(up);}
        void move(float xRelativ, float yRelativ) {m_position.first+=xRelativ;m_position.second+=yRelativ;}
        void move(pair<float,float> p){m_position.first+=p.first;m_position.second+=p.second;}


        virtual ~Movable();
    protected:
    private:
};

#endif // MOVABLE_H
