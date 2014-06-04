#include "core.h"

Core::Core(RenderWindow* window)
{
    loadContent();
    m_window=window;
    m_graphic=new Graphics(m_window);
}

void Core::loadContent()
{
    TextureFactory::load();
    AnimationFactory::load();
    TileFactory::load();
}

void Core::update()
{

}

void Core::draw()
{
     m_window->clear(Color(4,139,154));
}

void Core::run()
{
    Event event;

    while (m_window->isOpen())
    {
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
    }
}

Core::~Core()
{
    delete m_graphic;
}
