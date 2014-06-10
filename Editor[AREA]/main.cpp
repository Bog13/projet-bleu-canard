#include <iostream>
#include <ctime>
#include <iomanip>
#include"../include/global.h"
#include"../include/texturefactory.h"
#include"../include/animationfactory.h"
#include"../include/tilefactory.h"
#include"../include/areafactory.h"
#include "editor.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
void updateFps(float &fps,int &clockFps,RenderWindow *window);

int main()
{
    RenderWindow window(VideoMode(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT),"Editor[AREA]");


    TextureFactory::load("../data/img/");
    AnimationFactory::load();
    TileFactory::load();
    AreaFactory::load();

    int currentID=1;
    bool interact=false;

    Vector2i mouse_position;

    ///FPS
    Clock clock;//pour calculer le fps
    clock.restart();
    float fps=0.;
    int clockFps=0;//fréquence d'affichage
    ///

    Editor theEditor(&window);
    Event event;

    while (window.isOpen())
    {
        clock.restart();

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



                case Event::MouseButtonPressed:
                    if(Mouse::isButtonPressed(Mouse::Left))interact=true;;
                    //if(Mouse::isButtonPressed(Mouse::Right)); on peux ajouter un clique droit ici
                    break;

                case Event::MouseButtonReleased:
                    interact=false;
                    break;
                default: break;


            }




        }
         mouse_position=Mouse::getPosition(window);  //window.mapPixelToCoords( peut servir
        if(interact){theEditor.Modify(mouse_position, currentID);}

        window.clear(Color(4,139,154));
        theEditor.Update();

        theEditor.Draw();
        window.display();

        if(clock.getElapsedTime().asMilliseconds()!=0)fps=1000/clock.getElapsedTime().asMilliseconds();
        updateFps(fps,clockFps,&window);


    }

    return 0;
}

void updateFps(float &fps,int &clockFps,RenderWindow *window)
{
    if(time(NULL)-clockFps>1)
    {
        window->setTitle("EDITOR ("+Global::intToStr(fps)+" fps)");
        clockFps=time(NULL);
    }
}
