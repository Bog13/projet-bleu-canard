#ifndef AREAMANAGER_H
#define AREAMANAGER_H
#include "area.h"
/*
    Contient les m�thodes qui Modifient les zones.
*/

class AreaManager
{
    public:
        AreaManager();
        virtual ~AreaManager();
    protected:
        Area* m_area;
    private:
};

#endif // AREAMANAGER_H
