#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "object.h"
#include "player.h"
#include "core.h"

class ObjectFactory
{
    public:
        ObjectFactory();
        static Object* create(Area* a,int id,float x,float y,float w,float h,bool solid);
        static Object get(int id);
        static void load();
        virtual ~ObjectFactory();
    protected:
        static vector<Object> m_objects;
    private:
};

#endif // OBJECTFACTORY_H
