#ifndef CREDITCONTROL_H
#define CREDITCONTROL_H
#include "creditmanager.h"
#include "controlengine.h"

class CreditControl: public ControlEngine
{
    public:
        CreditControl();
        virtual ~CreditControl();
    protected:
        CreditManager* m_manager;
    private:
};

#endif // CREDITCONTROL_H
