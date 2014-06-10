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

    ///FPS
    Clock clock;//pour calculer le fps
    clock.restart();
    float fps=0.;
    int clockFps=0;//fréquence d'affichage
    ///

    ///VIEW
    bool interact=false,
        movingRight=false,
        movingUp=false,
        movingLeft=false,
        movingDown=false;

    View mainView(FloatRect(0,0,Global::TILE_WIDTH*10,Global::TILE_HEIGHT*10));
         mainView.setViewport(FloatRect(0,0,1,0.88));
    View menuView(FloatRect(0,0,Global::TILE_WIDTH*Global::NB_TOTAL_TILE,Global::TILE_HEIGHT*10));
         menuView.setViewport(FloatRect(0,0.88f,1,1));
    ///


    Editor theEditor(&window, &mainView, &menuView);
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
                      ///VIEW CONTROL
                      case Keyboard::Subtract:  mainView.zoom(1.1f);break;
                      case Keyboard::Add:       mainView.zoom(0.9f) ;break;

                      case Keyboard::Left:      movingLeft=true;    break;
                      case Keyboard::Right:     movingRight=true;   break;
                      case Keyboard::Up:        movingUp=true;      break;
                      case Keyboard::Down:      movingDown=true;    break;

                      default: break;
                  }
                }
                case:: Event::KeyReleased:
                    switch(event.key.code)
                            {
                                ///View
                                case Keyboard::Left:      movingLeft=false;   break;
                                case Keyboard::Right:     movingRight=false;  break;
                                case Keyboard::Up:        movingUp=false; break;
                                case Keyboard::Down:      movingDown=false;  break;
                                default: break;
                            }


                case Event::MouseButtonPressed:
                    if(Mouse::isButtonPressed(Mouse::Left))interact=true;;
                    //if(Mouse::isButtonPressed(Mouse::Right)); on peux ajouter un clique droit ici On peut même mêtre un deuxième modifer tiens !
                    break;

                case Event::MouseButtonReleased:
                    interact=false;
                    break;
                default: break;


            }




        }

    ///Keyboard
        //Save
    if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::S) )
    {
        string name;
        cout<<" Sous quel nom enregistrer cette Area ? (x.txt) " << endl;
        cin >> name;
        theEditor.SaveCurrentArea(name);
    }
        //Load
    if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::L) )
    {
        string name;
        cout<<" Sous quel nom est enregistree l'Area souhaitee ?(x.txt) " << endl;
        cin >> name;
        theEditor.LoadArea(name);
    }


    ///Mouse
        Vector2i mouseWindowPosition=Mouse::getPosition(window);

    ///Updates
        theEditor.Update(mouseWindowPosition,interact,movingRight, movingLeft, movingUp, movingDown);

    ///WINDOW
        window.clear(Color(4,139,154));
        theEditor.draw();
        window.display();
        ////

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
