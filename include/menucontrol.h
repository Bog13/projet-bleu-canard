#ifndef MENUCONTROL_H
#define MENUCONTROL_H
/*
    Gestion des contr�les dans le menu
*/

#include "controlengine.h"
#include "menumanager.h"
class MenuControl: public ControlEngine
{
    public:
        MenuControl();
        virtual ~MenuControl();
    protected:
        MenuManager* m_manager;
    private:
};

#endif // MENUCONTROL_H
