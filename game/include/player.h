#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
/*
#include "global.h"
#include "object.h"
#include "controlable.h"
#include "movable.h"
*/
#include "object.h"
#include "controlable.h"
#include "movable.h"

class Area;

using namespace std;

class Player:public Object,public Controlable,public Movable
{
    public:
        Player(Area *a, Controller* c);
        Player(Area *a, Controller* c, int type,float x, float y,float w,float h,bool obs);
        void update();
        void updateControlable();
        void init();
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
