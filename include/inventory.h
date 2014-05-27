#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>

/*
    Ensemble des objets possédés par un personnage
*/

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();
    protected:
        std::vector<Item*> m_items;
    private:
};

#endif // INVENTORY_H
