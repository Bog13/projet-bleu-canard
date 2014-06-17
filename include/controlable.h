#ifndef CONTROLABLE_H
#define CONTROLABLE_H
#include <iostream>
#include "controller.h"
using namespace std;

class Controlable
{
    public:
        Controlable(Controller* c);
        void setController(Controller* c){m_controller=c;}
        Controller* getController(){return m_controller;}
        virtual void updateControlable();
        virtual ~Controlable();
    protected:
        Controller *m_controller;
    private:
};

#endif // CONTROLABLE_H
