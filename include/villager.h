#ifndef VILLAGER_H
#define VILLAGER_H

#include <npc.h>

/*
    NPC des villes possèdant un rôle social en général.
*/

class Villager : public NPC
{
    public:
        Villager();
        virtual ~Villager();
    protected:
    private:
};

#endif // VILLAGER_H
