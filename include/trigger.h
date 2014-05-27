#ifndef TRIGGER_H
#define TRIGGER_H

#include <tile.h>

/*
    Classe fille des Tile permettant une activité lors du déclanchement (torche, porte etc)
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
