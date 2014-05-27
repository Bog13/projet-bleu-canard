#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#include "controlengine.h"
#include "worldmanager.h"

class GameControl: public ControlEngine
{
    public:
        GameControl();
        virtual ~GameControl();
    protected:
        WorldManager* m_manager;
    private:
};

#endif // GAMECONTROL_H
