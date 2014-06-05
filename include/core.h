#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "texturefactory.h"
#include "animationfactory.h"
#include "graphics.h"
#include "entitygraphic.h"
#include "areagraphic.h"
#include "areafactory.h"
#include "charactergraphic.h"
using namespace std;
using namespace sf;

class Core
{
    public:

        Core(RenderWindow *window);
        void run();
        void update();
        void draw();

        virtual ~Core();

    protected:
        RenderWindow* m_window;
        Graphics* m_graphic;
        AreaGraphic *m_ag;
        Area *m_a;
        CharacterGraphic *m_c;
        ///

        int m_fps;
        int m_clockFps;
        Clock m_clock;

        bool m_viewActivated;



    private:
};

#endif // CORE_H
