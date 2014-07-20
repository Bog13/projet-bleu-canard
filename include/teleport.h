#ifndef TELEPORT_H
#define TELEPORT_H

#include "effect.h"
#include "global.h"
#include "positionable.h"


class Teleport : public Effect
{
    public:
        Teleport();

        Teleport(Tile* t, float x, float y);
        void setPosition(float x, float y){m_xt=x;m_yt=y;}

        void apply();
        virtual ~Teleport();
    protected:
        float m_xt;
        float m_yt;
};

#endif // TELEPORT_H
