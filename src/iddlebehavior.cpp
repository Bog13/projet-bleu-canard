#include "iddlebehavior.h"

IddleBehavior::IddleBehavior(Object* obj):Behavior(obj)
{
    //ctor
}

void IddleBehavior::doSomething()
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

IddleBehavior::~IddleBehavior()
{
    //dtor
}
