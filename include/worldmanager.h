#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include "world.h"

/*
    modifie le monde
*/
class WorldManager
{
    public:
        WorldManager();
        virtual ~WorldManager();
    protected:
        World* m_world;
    private:
};

#endif // WORLDMANAGER_H
