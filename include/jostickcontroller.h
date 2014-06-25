#ifndef JOSTICKCONTROLLER_H
#define JOSTICKCONTROLLER_H
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>
#include "controller.h"
using namespace std;
using namespace sf;

class JostickController:public Controller
{
    public:
        JostickController();
        virtual bool up();
        virtual bool down();
        virtual bool left();
        virtual bool right();

        virtual bool yes();
        virtual bool no();

        virtual bool noOp();

        virtual ~JostickController();
    protected:
        bool m_loaded;
    private:
};




#endif // JOSTICKCONTROLLER_H
