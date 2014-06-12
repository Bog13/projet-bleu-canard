#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "object.h"
using namespace std;

class Character: public Object
{
    public:
        Character();
        Character(int type,float x, float y,float w,float h);
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
