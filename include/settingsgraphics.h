#ifndef SETTINGSGRAPHICS_H
#define SETTINGSGRAPHICS_H

#include "settingsobserver.h"
#include "graphicsengine.h"

class SettingsGraphics: public GraphicsEngine, SettingsObserver
{
    public:
        SettingsGraphics();
        virtual ~SettingsGraphics();
    protected:
    private:
};

#endif // SETTINGSGRAPHICS_H
