#include "iddlebehavior.h"

#include "movable.h"
#include "object.h"

IddleBehavior::IddleBehavior(Object* obj):Behavior(obj)
{
    //ctor
}

IddleBehavior::IddleBehavior():Behavior(0)
{
    //ctor
}

void IddleBehavior::squareWalk()
{
    Movable *m= dynamic_cast<Movable*>(m_object);

    if(m!=0)
    {
        if(time(NULL)%4==0)m->moveUp();
        else if(time(NULL)%4==1)m->moveRight();
        else if(time(NULL)%4==2)m->moveDown();
        else if(time(NULL)%4==3)m->moveLeft();


    }
}

void IddleBehavior::doSomething()
{
    if(time(NULL)%8<4){}
    else {squareWalk();}
}

IddleBehavior::~IddleBehavior()
{
    //dtor
}
