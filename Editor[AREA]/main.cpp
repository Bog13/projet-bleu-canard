#include <iostream>
#include <ctime>
#include <iomanip>
#include"../include/global.h"
#include"../include/texturefactory.h"
#include"../include/animationfactory.h"
#include"../include/tilefactory.h"
#include"../include/areafactory.h"
#include"../include/objectfactory.h"
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
    ObjectFactory::load;
    AreaFactory::load();


    ///FPS
    Clock clock;//pour calculer le fps
    clock.restart();
    float fps=0.;
    int clockFps=0;//fréquence d'affichage
    ///

    ///VIEW
    bool viewMoovement[4], interact=false;


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
// TODO (j0sh-u_a#1#): Refonte de editor::zoom(float f)
                    case Keyboard::Subtract:  theEditor.zoom(1.1f);break;
                    case Keyboard::Add:       theEditor.zoom(0.9f) ;break;

                    case Keyboard::Right:
                            viewMoovement[RIGHT]=true;
                            break;

                        case Keyboard::Left:
                            viewMoovement[LEFT]=true;
                            break;

                        case Keyboard::Up:
                            viewMoovement[UP]=true;
                            break;

                        case Keyboard::Down:
                            viewMoovement[DOWN]=true;
                            break;

                        default:
                            break;
                  }
                }

                case Event::KeyReleased:

                    switch(event.key.code)
                    {
                        case Keyboard::Right:
                            viewMoovement[RIGHT]=false;
                            break;

                        case Keyboard::Left:
                            viewMoovement[LEFT]=false;
                            break;

                        case Keyboard::Up:
                            viewMoovement[UP]=false;
                            break;

                        case Keyboard::Down:
                            viewMoovement[DOWN]=false;
                            break;

                        default:
                            break;
                        } break;

                ///MOUSE
                case Event::MouseButtonPressed:
                    if(Mouse::isButtonPressed(Mouse::Left))interact=true;;
                    //if(Mouse::isButtonPressed(Mouse::Right)); on peux ajouter un clique droit ici On peut même mettre un deuxième modifier tiens !
                break;

                case Event::MouseButtonReleased:
                    interact=false;
                    break;


                default: break;


            }

            if(Keyboard::isKeyPressed(Keyboard::Space)){theEditor.loadArea("areaTest.area");}///DEBUG






        }


        //Save
    if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::S) )
    {
        string name;
        cout<<" Sous quel nom enregistrer cette Area ? (x.txt) " << endl;
        cin >> name;
        theEditor.saveCurrentArea(name);
    }
        //Load
    if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::L) )
    {
        string name;
        cout<<" Sous quel nom est enregistree l'Area souhaitee ?(x.txt) " << endl;
        cin >> name;
        theEditor.loadArea(name);
    }


    /// camera
    theEditor.getCamera()->moveView(viewMoovement[RIGHT],viewMoovement[LEFT], viewMoovement[UP],viewMoovement[DOWN]);


    ///Mouse
        //position de la souris relative à la fenêtre
        Vector2i mouseWindowPosition=Mouse::getPosition(window);

    ///Updates
        theEditor.update(mouseWindowPosition,interact);

    ///WINDOW
        window.clear(Color(4,139,154));
        theEditor.draw();
        window.display();
        ////

    ///FPS
        if(clock.getElapsedTime().asMilliseconds()!=0)Global::FPS=1000/clock.getElapsedTime().asMilliseconds();
    }

    return 0;
}
///A voir
void updateFps(float &fps,int &clockFps,RenderWindow *window)
{
    if(time(NULL)-clockFps>1)
    {
        window->setTitle("EDITOR ("+Global::intToStr(fps)+" fps)");
        clockFps=time(NULL);
    }
}
