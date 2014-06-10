#include <iostream>

#include"../include/global.h"
#include"../include/texturefactory.h"
#include"../include/areafactory.h"
#include "editor.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT),"Editor[AREA]");

    TextureFactory::loadPng("../data/img/tileset.png",1,4);
    AnimationFactory::load();
    TileFactory::load();
    AreaFactory::load();

    int currentID=1;

    Editor theEditor(&window);
    Event event;

    while (window.isOpen())
    {

        Vector2i mouse_position=Mouse::getPosition(window);  //window.mapPixelToCoords( peut servir
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::KeyPressed:
                {
                  switch(event.key.code)
                  {
                      case Keyboard::Escape: window.close();
                      default: break;
                  }
                }



            /*case Event::MouseButtonPressed:
                {
                    switch(Mouse::isButtonPressed)
                        {cout <<"done ?"<<endl;
                        case Mouse::Left:
                            {theEditor.Modify(mouse_position, currentID); }

                        default: break;
                        }
                }*/
                default: break;

            }

            if(Mouse::isButtonPressed(Mouse::Left))
            {
                theEditor.Modify(mouse_position, currentID);
                cout << "x= " << mouse_position.x << " y= " << mouse_position.y << endl;
            }

            //if(Mouse::ButtonPressed(Mouse::Left));
        }

    window.clear(Color(4,139,154));
    theEditor.Draw();
    window.display();
    }

    return 0;
}
