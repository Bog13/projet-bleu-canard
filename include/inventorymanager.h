#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "inventory.h"

/*
    Capable de modifier l'inventaire.
*/

class InventoryManager
{
    public:
        InventoryManager();
        virtual ~InventoryManager();
    protected:
        Inventory* m_inventory;
    private:
};

#endif // INVENTORYMANAGER_H
