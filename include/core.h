#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "texturefactory.h"
#include "animationfactory.h"
#include "graphics.h"
#include "tilegraphic.h"
using namespace std;
using namespace sf;

class Core
{
    public:

        Core(RenderWindow *window);
        void run();
        void update();
        void draw();
        void loadContent();
        virtual ~Core();

    protected:
        RenderWindow* m_window;
        Graphics* m_graphic;

    private:
};

#endif // CORE_H
