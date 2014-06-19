#ifndef BEHAVIOR_H
#define BEHAVIOR_H
#include <iostream>
#include "object.h"
using namespace std;

class Behavior
{
    public:
        Behavior(Object* obj);
        Behavior();

        virtual void doSomething()=0;

        Object* getObject(){return m_object;}
        void setObject(Object* o){m_object=o;}
        virtual ~Behavior();
    protected:
    Object* m_object;
    private:
};

#endif // BEHAVIOR_H
