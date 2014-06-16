#include "core.h"

enum
{
    RIGHT=0,
    DOWN=1,
    LEFT=2,
    UP=3
};

Core::Core(RenderWindow* window)
{

    m_window=window;
    m_graphic=new Graphics(m_window);
    m_graphic->setViewSize(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT);

    /// test area
    m_a=new Area(50,50);
    //AreaFactory::loadArea(m_a,"areaTest.txt");
    m_a->addObject(new Object(CHAR_NONE,10,10,32,64,true));
    m_a->addObject(new Object(PINE_TREE,100,100,64,64,true));
    m_ag=new AreaGraphic(m_a);
    m_ag->getObjectGraphic(0)->getAnimation()->setDelay(125);
    ///


    m_fps=0;
    m_clockFps=0;
    m_clock.restart();

    m_viewActivated=false;
}


void Core::update()
{
    m_ag->update();
    if(time(NULL)-m_clockFps>=1)
    {
        m_window->setTitle(Global::intToStr(m_fps)+" fps");

        m_clockFps=time(NULL);
    }

    m_graphic->update();
}

void Core::draw()
{
     m_window->clear(Color(4,139,154));
     m_graphic->drawVisibleArea(m_ag);
     m_graphic->drawObjects(m_ag);
}




void Core::run()
{
    bool viewMoovement[4]; ///Bool pour le contrôle de la view
    for(int i(0);i<4;i++){viewMoovement[i]=false;}
    Event event;

    while (m_window->isOpen())
    {
        m_clock.restart();

        while(m_window->pollEvent(event))
        {
            switch(event.type)
            {

                case Event::Closed:
                    m_window->close();
                    break;

                case Event::KeyPressed:

                    switch(event.key.code)
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
                            m_graphic->enableView(m_viewActivated);
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
                        }

                        default:
                            break;
                    }
                    break;



            }
        ///View Update
        if(viewMoovement[RIGHT]){m_graphic->moveViewRight(0.5);}
        if(viewMoovement[UP]){m_graphic->moveViewUp(0.5);}
        if(viewMoovement[LEFT]){m_graphic->moveViewLeft(0.5);}
        if(viewMoovement[DOWN]){m_graphic->moveViewDown(0.5);}
        else{}
        //m_graphic->moveView(viewMoovement[RIGHT]*0.5,viewMoovement[LEFT]*0.5,viewMoovement[UP]*0.5,viewMoovement[DOWN]*0.5);
        ///

        draw();
        update();
        m_window->display();


        ///fps
        if(m_clock.getElapsedTime().asMilliseconds() != 0) m_fps= 1000/m_clock.getElapsedTime().asMilliseconds();
        ///
    }
}

Core::~Core()
{
delete m_ag;delete m_a;//test area
delete m_graphic;
}
