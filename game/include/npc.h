#ifndef NPC_H
#define NPC_H
#include <iostream>

/*
#include "global.h"
#include "controlable.h"
#include "behavior.h"*/

#include "object.h"
#include "movable.h"
#include "ia.h"

using namespace std;

class Behavior;
class Area;


class NPC: public Object, public Movable, public IA
{
    public:
        NPC(Behavior* be,Area *a, int type,float x, float y,float w,float h,bool b=true);
        void update();
        virtual ~NPC();
    protected:

    private:
};

#endif // NPC_H
