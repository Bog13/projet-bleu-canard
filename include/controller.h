#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Controller
{
    public:
        Controller();

        virtual bool up()=0;
        virtual bool down()=0;
        virtual bool left()=0;
        virtual bool right()=0;

        virtual bool yes()=0;
        virtual bool no()=0;

        virtual bool noOp()=0;

        Event* getEvent(){return &m_event;}



        virtual ~Controller();
    protected:
        Event m_event;
    private:
};

#endif // CONTROLLER_H
