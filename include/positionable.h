#ifndef POSITIONABLE_H
#define POSITIONABLE_H
#include <iostream>
#include <utility>
#include "collisionable.h"
#include "global.h"
using namespace std;

class Area;


class Positionable
{
    public:
        Positionable(Area *a,pair<float,float> pos);
        Positionable(Area *a,float x,float y);
        Positionable(Area *a,float x,float y,float w,float h);
        Positionable(Area *a);
        pair<float,float> getPosition(){return m_position;}
        void setPosition(Area *a,float x,float y){m_currentArea=a;m_position=pair<float,float>(x,y);}
        void setPosition(float x,float y){m_position=pair<float,float>(x,y);}

        void setPosition(pair<float,float> pos){m_position=pos;}
        float getX(){return m_position.first;}
        float getY(){return m_position.second;}
        float getWidth(){return m_width;}
        float getHeight(){return m_height;}
        Vector2f getSize() {return Vector2f(m_width,m_height);}

        bool collideWith(float x,float y,float w,float h);

        void setWidth(float w){m_width=w;}
         void setHeight(float h){m_height=h;}
         void setSize(Vector2f v) {m_width=v.x; m_height=v.y;}

        Area* getArea(){return m_currentArea;}
        void setArea(Area* a) {m_currentArea=a;}
        virtual ~Positionable();
    protected:
        pair<float,float> m_position;
        float m_width;
        float m_height;
        Area* m_currentArea;


    private:
};

#endif // POSITIONABLE_H
