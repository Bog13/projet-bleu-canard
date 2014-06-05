#ifndef OBJECT_H
#define OBJECT_H

#include "tile.h"


class Object : public Tile
{
    public:
        Object();
        Object(float positionX, float positionY);
        virtual ~Object();

        float GetpositionX() { return m_positionX; }
        void SetpositionX(float val) { m_positionX = val; }

        float GetpositionY() { return m_positionY; }
        void SetpositionY(float val) { m_positionY = val; }

        Vector2f GetPosition() {return Vector2f(m_positionX,m_positionY);}
        void SetPosition(float x, float y)  {m_positionX=x; m_positionY=y;}

        void Move(float x=0, float y=0) {m_positionX+=x; m_positionY+=y;} ///A revoir niveau colision je présume.

    protected:

        float m_positionX;
        float m_positionY;
    private:
};

#endif // OBJECT_H
