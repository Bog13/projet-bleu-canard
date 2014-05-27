#ifndef BUILDING_H
#define BUILDING_H
/*
    Un bâtiment est une tuile possédant une porte qui téléporte dans une zone
*/
#include "teleporter.h"

class Building
{
    public:
        Building();
        virtual ~Building();
    protected:
        Teleporter* m_door;
    private:
};

#endif // BUILDING_H
