#ifndef AREA_H
#define AREA_H
#include "../include/tile.h"
#include "../include/character.h"
#include <vector>
/*
    zone à proprement dire du monde, la zone où se trouve le joueur sera affichée, les autres continueront d'évoluer.
*/

class Area
{
    public:
        Area();
        virtual ~Area();
    protected:
        std::vector<Tile*> m_tiles;
        std::vector<Character*> m_characters;
    private:
};

#endif // AREA_H
