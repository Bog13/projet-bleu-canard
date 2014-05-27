#include <iostream>
#include "../include/tool.h"
#include "../include/global.h"
#include "../include/area.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

ConvexShape createConvex(int x,int y,int w,int h)
{
    ConvexShape shape(4);
    shape.setPoint(0,Vector2f(0,0));
}

/*
void display(Area* area,RenderWindow* window)
{
    for(int i=0;i<Global::NB_TILE_HEIGHT;i++)
    {
        for(int j=0;j<Global::NB_TILE_WIDTH;j++)
        {

        }
    }
}*/

int main()
{

    RenderWindow window(VideoMode(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT),"Test");
    Event event;
    Area currentArea;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                    window.close();
                    break;

                case Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case Keyboard::Escape:
                            window.close();
                            break;
                        case Keyboard::A:
                            Tool::Save("test.txt","Je suis un bel idiot 123456789");
                            break;

                        default:
                            break;
                    }
                    break;

                        default:
                            break;
            }
        }

        window.clear(Color(4,139,154));
        window.display();
    }


    return 0;
}
