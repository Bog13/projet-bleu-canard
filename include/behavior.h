#ifndef BEHAVIOR_H
#define BEHAVIOR_H
#include "charactermanager.h"
/*
    Classe g�n�rale de l'IA.
*/

class Behavior
{
    public:
        Behavior();
        virtual ~Behavior();
    protected:
        CharacterManager* m_characterManger;
    private:
};

#endif // BEHAVIOR_H
