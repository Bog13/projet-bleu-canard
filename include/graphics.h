#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "tilefactory.h"
#include "tilegraphic.h"
#include "areagraphic.h"
using namespace std;
using namespace sf;

class AreaGraphic;
class Graphics
{
    public:
        Graphics(RenderWindow* window);
        static ConvexShape createSquare(int x,int y,int w,int h);
        void drawTile(TileGraphic t);
        void drawArea(AreaGraphic *ag);
        virtual ~Graphics();
    protected:
        RenderWindow* m_window;
    private:
};

#endif // GRAPHICS_H
