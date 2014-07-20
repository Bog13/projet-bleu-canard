#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "texturefactory.h"
#include "animationfactory.h"
#include "animation.h"
#include "graphics.h"
#include "entitygraphic.h"
#include "areagraphic.h"
#include "areafactory.h"
#include "player.h"
#include "npc.h"
#include "behavior.h"
#include "iddlebehavior.h"
#include "controller.h"
#include "keyboardcontroller.h"
#include "objectfactory.h"

using namespace std;
using namespace sf;



class Core
{
    public:

        Core(RenderWindow *window);
        void run();
        void update();
        void lookAtControl();
        void draw();
        void changeCurrentArea(string fileName);

        virtual ~Core();

        static Controller* m_controller;

    protected:
        RenderWindow* m_window;
        Graphics* m_graphic;

        AreaGraphic *m_ag;
        Area *m_a;
        ///

        int m_fps;

        int m_clockFps;
        Clock m_clock;

        Player* m_player1;

        bool m_viewActivated;



    private:
};

#endif // CORE_H
