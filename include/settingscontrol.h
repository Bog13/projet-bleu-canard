#ifndef SETTINGSCONTROL_H
#define SETTINGSCONTROL_H
#include "settingsmanager.h"
#include "controlengine.h"

class SettingsControl: public ControlEngine
{
    public:
        SettingsControl();
        virtual ~SettingsControl();
    protected:
        SettingsManager* m_manager;
    private:
};

#endif // SETTINGSCONTROL_H
