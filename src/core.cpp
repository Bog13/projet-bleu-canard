#include "core.h"



Core::Core(RenderWindow* window)
{

    m_window=window;

    m_controller=new KeyboardController();

    /// test area
    m_a=new Area(Global::NB_TILE_WIDTH*3,Global::NB_TILE_HEIGHT*3);



    Player *p=new Player(m_a,m_controller,CHAR_NONE,10,300,32,64,true);
    m_a->addObject(p);

    Object* jimmy= new NPC(new IddleBehavior,m_a,CHAR_NONE,80,400,32,64,true);
    m_a->addObject(jimmy);

    for(int i=1;i<10;i++) ///50*50 MAX (bug a partir de là)
    {
        for(int j=1;j<10;j++)
        {

            m_a->addObject(new Object(ObjectFactory::get(PINE_TREE)),i*150,j*150);

        }
    }








    ///

    ///graphics
    m_ag=new AreaGraphic(m_a);
    m_graphic=new Graphics(m_window,m_ag);

    m_graphic->getCamera()->setTarget(p);
    m_graphic->getCamera()->setViewSize(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT);


    ///areagraphic


    ///


    m_fps=0;
    m_clockFps=0;
    m_clock.restart();

    m_viewActivated=false;
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
    m_graphic->drawVisibleArea();///DEBUG
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
    delete m_ag;delete m_a;//test area
    delete m_graphic;
    delete m_controller;
}
