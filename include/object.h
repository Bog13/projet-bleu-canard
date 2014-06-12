#ifndef OBJECT_H
#define OBJECT_H

#include "tile.h"
#include "positionable.h"

class Object : public Tile,public Positionable
{
    public:
        Object();
        Object(int type,float x, float y,float w,float h);
        Object(int type,float x, float y,float w,float h,bool obs);
        virtual ~Object();

        float getWidth(){return m_width;}
        float getHeight(){return m_height;}

        bool isAnObstacle(){return m_isAnObstacle;}
        void setObstacleStatus(int b){m_isAnObstacle=b;}

    protected:


        float m_width;
        float m_height;
        bool m_isAnObstacle;
    private:
};

#endif // OBJECT_H
