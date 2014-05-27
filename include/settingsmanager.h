#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H
#include <vector>
#include "settingsobserver.h"
#include "settings.h"

class SettingsManager
{
    public:
        SettingsManager();
        virtual ~SettingsManager();
    protected:
        Settings* m_settings;
        std::vector<SettingsObserver*> m_vecObserver;
    private:
};

#endif // SETTINGSMANAGER_H
