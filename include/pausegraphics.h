#ifndef PAUSEGRAPHICS_H
#define PAUSEGRAPHICS_H
/*
    affichage �cran pause
*/
#include "pauseobserver.h"
#include "graphicsengine.h"

class PauseGraphics:public PauseObserver,GraphicsEngine
{
    public:
        PauseGraphics();
        virtual ~PauseGraphics();
    protected:
    private:
};

#endif // PAUSEGRAPHICS_H
