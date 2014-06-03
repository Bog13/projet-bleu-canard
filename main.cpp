#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800,600), "test");
    Event event;

    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch(event.type)
            {

                case Event::Closed:
                    window.close();
                    break;

                default:
                    break;

                case Event::KeyPressed:

                    switch(event.key.code)
                    {

                        case Keyboard::Escape:
                            window.close();
                            break;

                        default:
                            break;
                    }
                    break;
            }
        }

        window.clear(Color(4,139,154));
        window.display();
    }
    return 0;
}
