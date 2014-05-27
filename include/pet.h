#ifndef PET_H
#define PET_H

#include <npc.h>

/*
    Classe majeur du jeu, comportant tous les pets possibles, héritant de character et donc de NPC (enfin l'inverse).
*/

class Pet : public NPC
{
    public:
        Pet();
        virtual ~Pet();
    protected:
    private:
};

#endif // PET_H
