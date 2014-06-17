#ifndef IDDLEBEHAVIOR_H
#define IDDLEBEHAVIOR_H
#include <iostream>
#include <ctime>
#include "object.h"
#include "behavior.h"

using namespace std;

class IddleBehavior:public Behavior
{
    public:
        IddleBehavior(Object* obj);
        void doSomething();
        virtual ~IddleBehavior();
    protected:
    private:
};

#endif // IDDLEBEHAVIOR_H
