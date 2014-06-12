#ifndef POSITIONABLE_H
#define POSITIONABLE_H
#include <iostream>
#include <utility>
using namespace std;
class Positionable
{
    public:
        Positionable(pair<float,float> pos);
        Positionable(float x,float y);
        Positionable();
        pair<float,float> getPosition(){return m_position;}
        void setPosition(float x,float y){m_position=pair<float,float>(x,y);}
        void setPosition(pair<float,float> pos){m_position=pos;}
        float getX(){return m_position.first;}
        float getY(){return m_position.second;}

        virtual ~Positionable();
    protected:
        pair<float,float> m_position;
    private:
};

#endif // POSITIONABLE_H
