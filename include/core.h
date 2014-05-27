#ifndef CORE_H
#define CORE_H
/*
    Cerveau du jeu
*/
#include "controler.h"
#include "engine.h"

class Core
{
    public:
        Core();
        virtual ~Core();
    protected:
        Controler* m_control;
        Engine* m_gEngine;
        Engine* m_sEngine;
        Engine* m_cEngine;
    private:
};

#endif // CORE_H
