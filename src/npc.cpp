#include "npc.h"

NPC::NPC(Behavior* be,Area *a, int type,float x, float y,float w,float h,bool b):Object(a,type,x,y,w,h,b), Movable(this,this), IA(be)
{
    m_speed=pair<float,float>(0.15,0.15);
    setHitbox(0,(3/4.)*getHeight(),getWidth(),(1/4.)*getHeight());
}

void NPC::update()
{
    doSomething();

}

NPC::~NPC()
{
    //dtor
}
