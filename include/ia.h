#ifndef IA_H
#define IA_H
#include <iostream>
#include "behavior.h"
using namespace std;

class IA
{
    public:
        IA(Behavior* b);
        void doSomething();
        virtual ~IA();
    protected:
        Behavior* m_behavior;
    private:
};

#endif // IA_H
