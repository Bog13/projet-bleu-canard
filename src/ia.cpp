#include "ia.h"
#include "behavior.h"

IA::IA(Behavior *b):m_behavior(b)
{

}

void IA::doSomething()
{
    if(m_behavior!=0)
    {
        m_behavior->doSomething();
    }
}

IA::~IA()
{
    //dtor
}
