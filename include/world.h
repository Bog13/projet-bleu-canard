#ifndef WORLD_H
#define WORLD_H
#include "worldobserver.h"
#include "area.h"
#include <vector>
/*
ensemble des area permettant la gestion compl�te des donn�es cr�ant le monde. Contient un worldManager.
*/

class World
{
    public:
        World();
        virtual ~World();
    protected:
        std::vector<Area*> m_areas;
        std::vector<WorldObserver*> m_vecObs;
    private:
};

#endif // WORLD_H
