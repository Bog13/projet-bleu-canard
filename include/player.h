#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "global.h"
#include "object.h"
#include "controlable.h"
#include "movable.h"
using namespace std;

class Player:public Object,public Controlable,public Movable
{
    public:
        Player(Controller* c);
        Player(Controller* c, int type,float x, float y,float w,float h,bool obs);
        void update();
        void updateControlable();
        void init();
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
