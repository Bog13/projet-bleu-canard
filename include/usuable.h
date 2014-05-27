#ifndef USUABLE_H
#define USUABLE_H

#include <item.h>

/*
    Objet utilisable et non renouvelable
*/

class Usuable : public Item
{
    public:
        Usuable();
        virtual ~Usuable();
    protected:
    private:
};

#endif // USUABLE_H
