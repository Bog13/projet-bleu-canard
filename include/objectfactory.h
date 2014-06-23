#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "object.h"

class ObjectFactory
{
    public:
        ObjectFactory();

        static Object* get(int id);
        static void load();
        virtual ~ObjectFactory();
    protected:
        static vector<Object> m_objects;
    private:
};

#endif // OBJECTFACTORY_H
