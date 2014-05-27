#ifndef CONTROLENGINE_H
#define CONTROLENGINE_H
/*
    Gère une configuration de contrôle donnée (jeu, menu etc)
*/
#include "engine.h"

class ControlEngine: public Engine
{
    public:
        ControlEngine();
        virtual ~ControlEngine();
    protected:
    private:
};

#endif // CONTROLENGINE_H
