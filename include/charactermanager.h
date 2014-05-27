#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H
#include "character.h"

class CharacterManager
{
    public:
        CharacterManager();
        virtual ~CharacterManager();
    protected:
        Character* m_character;
    private:
};

#endif // CHARACTERMANAGER_H
