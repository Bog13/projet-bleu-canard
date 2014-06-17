#ifndef OBJECT_H
#define OBJECT_H

#include "tile.h"
#include "positionable.h"
#include "movable.h"
#include "collisionable.h"
#include "area.h"

class Area;

class Object :
public Tile,
public Positionable,
public Collisionable

{
    public:
        Object();
        Object(int type,float x, float y,float w,float h);
        Object(int type,float x, float y,float w,float h,bool obs);
        virtual ~Object();
        void update();

    protected:


    private:
};

#endif // OBJECT_H
