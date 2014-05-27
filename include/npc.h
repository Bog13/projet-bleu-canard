#ifndef NPC_H
#define NPC_H

#include <character.h>
#include "behavior.h"
/*
    Class des personnages non joueurs comme les villageois, ennemi et pets comportant un Behavior.
*/

class NPC : public Character
{
    public:
        NPC();
        virtual ~NPC();
    protected:
        Behavior* m_behavior;
    private:
};

#endif // NPC_H
