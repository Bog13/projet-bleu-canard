#ifndef POSITIONABLE_H
#define POSITIONABLE_H
#include <iostream>
#include <utility>

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
        Area* getArea(){return m_currentArea;}
        virtual ~Positionable();
    protected:
        pair<float,float> m_position;
        float m_width;
        float m_height;
        Area* m_currentArea;


    private:
};

#endif // POSITIONABLE_H
