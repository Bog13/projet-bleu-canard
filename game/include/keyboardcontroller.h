#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>
#include "controller.h"
using namespace std;
using namespace sf;


class KeyboardController: public Controller
{
    public:
        KeyboardController();

        virtual bool up();
        virtual bool down();
        virtual bool left();
        virtual bool right();

        virtual bool yes();
        virtual bool no();

        virtual bool noOp();

        virtual ~KeyboardController();
    protected:
    private:
};

#endif // KEYBOARDCONTROLLER_H
