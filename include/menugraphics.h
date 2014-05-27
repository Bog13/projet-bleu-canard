#ifndef MENUGRAPHICS_H
#define MENUGRAPHICS_H

#include "menuobserver.h"
#include "graphicsengine.h"

class MenuGraphics: public MenuObserver,GraphicsEngine
{
    public:
        MenuGraphics();
        virtual ~MenuGraphics();
    protected:
    private:
};

#endif // MENUGRAPHICS_H
