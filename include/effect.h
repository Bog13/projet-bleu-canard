#ifndef EFFECT_H
#define EFFECT_H

//#include "tile.h"

class Tile;

class Effect
{
    public:
        Effect();
        Effect(Tile* t);

        void setTarget(Tile* t){m_target=t;}
        virtual void apply()=0;

        virtual ~Effect();
    protected:
        Tile* m_target;
};

#endif // EFFECT_H
