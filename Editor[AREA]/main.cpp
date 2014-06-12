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
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                {
                  switch(event.key.code)
                  {
                      case Keyboard::Escape: window.close();
                      ///VIEW CONTROL
                      case Keyboard::Subtract:  theEditor.zoom(1.1f);break;
                      case Keyboard::Add:       theEditor.zoom(0.9f) ;break;
                      default: break;
                  }
                }
                case:: Event::KeyReleased:
                    switch(event.key.code)
                    {
                        default: break;
                    }


                case Event::MouseButtonPressed:
                    if(Mouse::isButtonPressed(Mouse::Left))interact=true;;
                    //if(Mouse::isButtonPressed(Mouse::Right)); on peux ajouter un clique droit ici On peut même mettre un deuxième modifier tiens !
                    break;

                case Event::MouseButtonReleased:
                    interact=false;
                    break;
                default: break;


            }
            ///Keyboard
            if(Keyboard::isKeyPressed(Keyboard::Up)){movingUp=true;}else movingUp=false;
            if(Keyboard::isKeyPressed(Keyboard::Down)){movingDown=true;}else movingDown=false;
            if(Keyboard::isKeyPressed(Keyboard::Left)){movingLeft=true;}else movingLeft=false;
            if(Keyboard::isKeyPressed(Keyboard::Right)){movingRight=true;}else movingRight=false;

            if(Keyboard::isKeyPressed(Keyboard::Space)){theEditor.LoadArea("areaTest.area");}///DEBUG






        }


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

    ///Directions
    //cout<<movingRight<<endl;
    if(movingUp)theEditor.moveView(0,-.5);
    if(movingDown)theEditor.moveView(0,.5);
    if(movingLeft)theEditor.moveView(-.5,0);
    if(movingRight)theEditor.moveView(.5,0);
    if(!movingUp && !movingDown && !movingLeft && !movingRight)theEditor.moveView(0,0);
    ///Mouse
        Vector2i mouseWindowPosition=Mouse::getPosition(window);

    ///Updates
        theEditor.Update(mouseWindowPosition,interact);

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
