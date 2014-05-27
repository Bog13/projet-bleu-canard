#ifndef BUILDING_H
#define BUILDING_H
/*
    Un b�timent est une tuile poss�dant une porte qui t�l�porte dans une zone
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
