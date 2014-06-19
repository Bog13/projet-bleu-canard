#include "ia.h"

IA::IA(Behavior *b):m_behavior(b)
{

}

void IA::doSomething()
{
    m_behavior->doSomething();
}

IA::~IA()
{
    //dtor
}
