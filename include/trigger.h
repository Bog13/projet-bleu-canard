#ifndef TRIGGER_H
#define TRIGGER_H

#include <tile.h>

/*
    Classe fille des Tile permettant une activit� lors du d�clanchement (torche, porte etc)
*/

class Trigger : public Tile
{
    public:
        Trigger();
        virtual ~Trigger();
    protected:
    private:
};

#endif // TRIGGER_H
