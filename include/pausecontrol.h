#ifndef PAUSECONTROL_H
#define PAUSECONTROL_H
#include "pausemanager.h"
#include "controlengine.h"

class PauseControl: public ControlEngine
{
    public:
        PauseControl();
        virtual ~PauseControl();
    protected:
        PauseManager* m_manager;
    private:
};

#endif // PAUSECONTROL_H
