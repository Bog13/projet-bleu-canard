#include "core.h"

Core::Core(RenderWindow* window)
{

    m_window=window;
    m_graphic=new Graphics(m_window);

    /// test area
    a=new Area(1,1);
    AreaFactory::loadArea(a,"test2.txt");
    ag=new AreaGraphic(a);
    ///

    m_fps=0;
    m_clockFps=0;
    m_clock.restart();

    m_viewActivated=false;
}


void Core::update()
{
    ag->update();

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
     m_graphic->drawArea(ag);
}




void Core::run()
{
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

                default:
                    break;

                case Event::KeyPressed:

                    switch(event.key.code)
                    {

                        case Keyboard::Escape:
                            m_window->close();
                            break;




                        /**
                        La suite sert temporairement � tester la vue. CdC- ID 001 (Dropbox)
                            Concr�tement, appuyer sur V inverse la pr�sence d'une vue et les fl�ches dirigent.
                        **/
                        { /// Ouvre avec le '+' � gauche si n�cessaire.

                        case Keyboard::V:

                            m_viewActivated=!m_viewActivated;
                            m_graphic->enableView(m_viewActivated);
                            break;

                        case Keyboard::Right:
                            m_graphic->moveViewRight(10);
                            break;

                        case Keyboard::Left:
                            m_graphic->moveViewLeft(10);
                            break;

                        case Keyboard::Up:
                            m_graphic->moveViewUp(10);
                            break;

                        case Keyboard::Down:
                            m_graphic->moveViewDown(10);
                            break;

                        case Keyboard::Right && Keyboard::Up : /// Ca compile !
                            m_graphic->moveView(0,10,-10,0);
                            break;
                        }

                        default:
                            break;
                    }
                    break;
            }
        }


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
    delete ag;delete a;//test area
    delete m_graphic;
}