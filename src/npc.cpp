#include "npc.h"

#include "global.h"
#include "object.h"
#include "movable.h"
#include "ia.h"
#include "behavior.h"

NPC::NPC(Behavior* be,Area *a, int type,float x, float y,float w,float h,bool b):Object(a,type,x,y,w,h,b), Movable(this,this), IA(be)
{

    if(be != 0) be->setObject(this);

    m_absoluteSpeed=pair<float,float>(3*Global::TILE_WIDTH,2*Global::TILE_WIDTH);
    setHitbox(0,(3/4.)*getHeight(),getWidth(),(1/4.)*getHeight());
}

void NPC::update()
{
    updateMovable();

    if(m_behavior!=0)
    {
        doSomething();
    }

}

NPC::~NPC()
{
    //dtor
}
