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
                default:break;
                case Event::Closed:window.close();

                switch(event.key.code)
                {
                    default:break;
                    case Keyboard::Escape:window.close();
                }
            }
        }
        window.clear(Color(4,139,154));
        window.display();
    }
    return 0;
}
