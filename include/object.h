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
        Object(Area *a);
        Object(Area *a, int type,float x, float y,float w,float h);
        Object(Area *a, int type,float x, float y,float w,float h,bool obs);

        const void getInfo() {*this <<(cout);}
        void operator <<( std::ostream& os);
        virtual ~Object();
        void update();
        void operator=(Object o);
    protected:


    private:
};

#endif // OBJECT_H
