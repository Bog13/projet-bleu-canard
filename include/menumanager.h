#ifndef MENUMANAGER_H
#define MENUMANAGER_H
#include <vector>
#include "menu.h"
#include "menuobserver.h"

class MenuManager
{
    public:
        MenuManager();
        virtual ~MenuManager();
    protected:
        Menu* m_menu;
        std::vector<MenuObserver*> m_vecObserver;
    private:
};

#endif // MENUMANAGER_H
