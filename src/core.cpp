#include "core.h"

Core::Core(RenderWindow* window)
{

    m_window=window;
    m_graphic=new Graphics(m_window);
    ag=new AreaGraphic(4,4);

    m_fps=0;
    m_clockFps=0;
    m_clock.restart();
}


void Core::update()
{
    ag->update();

    if(time(NULL)-m_clockFps>=1)
    {
        m_window->setTitle(Global::intToStr(m_fps)+" fps");

        m_clockFps=time(NULL);
    }
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
    delete ag;
    delete m_graphic;
}
