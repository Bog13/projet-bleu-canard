#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H
/*
    Affichage du jeu (moteur de jeu principal)
*/
#include "graphicsengine.h"
#include "worldobserver.h"

class GameGraphics: public GraphicsEngine,WorldObserver
{
    public:
        GameGraphics();
        virtual ~GameGraphics();
    protected:
    private:
};

#endif // GAMEGRAPHICS_H
