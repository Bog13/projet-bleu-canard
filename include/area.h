#ifndef AREA_H
#define AREA_H
#include "../include/tile.h"
#include "../include/character.h"
#include <vector>
/*
    zone � proprement dire du monde, la zone o� se trouve le joueur sera affich�e, les autres continueront d'�voluer.
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
