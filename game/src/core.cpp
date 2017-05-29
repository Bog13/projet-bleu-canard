#include "core.h"

//data
#include "area.h"

//Graphism
#include "animation.h"
#include "graphics.h"
#include "entitygraphic.h"
#include "areagraphic.h"
#include "camera.h"


//Player
#include "player.h"
//#include "controller.h"
#include "keyboardcontroller.h"

//Ia etc
#include "npc.h"
#include "behavior.h"
#include "iddlebehavior.h"

//Usines
#include "objectfactory.h"
#include "areafactory.h"
#include "texturefactory.h"
#include "animationfactory.h"

//Tests
#include "teleport.h"

Controller* Core::m_controller=new KeyboardController();

Core::Core(RenderWindow* window)
{
    ///données
    m_window=window;
    //if(AreaFactory::loadArea(m_a,"ICI.txt")==false)m_a=new Area(20,20);
    m_a=new Area(20,20);
    AreaFactory::loadArea(m_a,Global::PATH_LVL+"main.txt");
        //player
    m_player1= new Player(m_a,m_controller,CHAR_NONE,10,300,32,64,true);
    Teleport* tp=new Teleport(0,0,0);
    m_player1->addEffect(tp);
    m_a->addObject(m_player1);

    ///graphics
    m_ag=new AreaGraphic(m_a);
    m_graphic=new Graphics(m_window,m_ag);

    m_graphic->getCamera()->setTarget(m_player1);
    m_graphic->getCamera()->setViewSize(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT);

    m_fps=0;
    m_clockFps=0;
    m_clock.restart();

    m_viewActivated=false;
}

void Core::changeCurrentArea(string fileName)
{
    AreaFactory::loadArea(m_a,fileName.c_str());
    m_ag=new AreaGraphic(m_a,m_graphic);
    m_graphic->getCamera()->mustRefresh();
    m_graphic->getCamera()->setTarget(m_player1);

}

void Core::update()
{

    //MaJ données
    m_ag->getArea()->update();

    //MaJ Graphique
    m_graphic->updateAreaTilesInCamera();

    m_ag->updateObjects();

    m_graphic->update();


    if(time(NULL)-m_clockFps>=1)
    {
        m_window->setTitle(Global::intToStr(m_fps)+" fps");

        m_clockFps=time(NULL);
    }


}

void Core::lookAtControl()
{


}

void Core::draw()
{
    //m_window->clear();
    m_graphic->drawVisibleArea();
    m_graphic->drawObjects();
}




void Core::run()
{
    bool viewMoovement[4]; ///Bool pour le contrôle de la view
    for(int i(0);i<4;i++){viewMoovement[i]=false;}



    while (m_window->isOpen())
    {
        m_clock.restart();

        while(m_window->pollEvent(*m_controller->getEvent()))
        {
            switch(m_controller->getEvent()->type)
            {

                case Event::Closed:
                    m_window->close();
                    break;

                case Event::KeyPressed:

                    switch((*m_controller->getEvent() ).key.code)
                    {

                        case Keyboard::Escape:
                            m_window->close();
                            break;

                        case Keyboard::Space:


                            break;


                        /**
                        La suite sert temporairement à tester la vue. CdC- ID 001 (Dropbox)
                            Concrètement, appuyer sur V inverse la présence d'une vue et les flèches dirigent.
                        **/
                         /// Ouvre avec le '+' à gauche si nécessaire.

                        case Keyboard::V:

                            m_viewActivated=!m_viewActivated;
                            m_graphic->enableCamera(m_viewActivated);
                            break;

                        ///TEST
                            case Keyboard::P:

                            changeCurrentArea("areaTest.txt");
                            break;

                            case Keyboard::M:
                            AreaFactory::loadArea(m_a,"test2.txt");
                            break;
                        ///

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
                    }break;



                case Event::KeyReleased:

                    switch(( *m_controller->getEvent() ).key.code)
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

                        default:
                            break;
                    }
                    break;



            }

        lookAtControl();

        // camera (Obsolète)
        //m_graphic->getCamera()->moveView(viewMoovement[RIGHT],viewMoovement[LEFT],viewMoovement[UP],viewMoovement[DOWN]);
        //

        update();
        draw();

        m_window->display();


        ///fps
        if(m_clock.getElapsedTime().asMicroseconds() != 0) m_fps= 1000000/m_clock.getElapsedTime().asMicroseconds();
        Global::FPS=m_fps;
        //if(Global::FPS>500)Global::FPS=500;
        ///
    }
}

Core::~Core()
{
    delete m_controller;
    delete m_graphic;
    delete m_ag;
    delete m_a;
}
