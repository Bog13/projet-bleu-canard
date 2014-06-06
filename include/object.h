#ifndef OBJECT_H
#define OBJECT_H

#include "tile.h"


class Object : public Tile
{
    public:
        Object();
        Object(int type,float x, float y,float w,float h);
        Object(int type,float x, float y,float w,float h,bool obs);
        virtual ~Object();

        float getX() { return m_x; }
        void setX(float val) { m_x = val; }

        float getY() { return m_y; }
        void setY(float val) { m_y = val; }

        float getWidth(){return m_width;}
        float getHeight(){return m_height;}

        Vector2f getPosition() {return Vector2f(m_x,m_y);}
        void setPosition(float x, float y)  {m_x=x; m_y=y;}

        bool isAnObstacle(){return m_isAnObstacle;}
        bool setObstacleStatus(int b){m_isAnObstacle=b;}

        void Move(float x=0, float y=0) {m_x+=x; m_y+=y;} ///A revoir niveau colision je présume.

    protected:

        float m_x;
        float m_y;
        float m_width;
        float m_height;
        bool m_isAnObstacle;
    private:
};

#endif // OBJECT_H
