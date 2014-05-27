#include <iostream>
#include "../include/tool.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800,600),"Test");
    Event event;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                    window.close();
                    break;

                case Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case Keyboard::Escape:
                            window.close();
                            break;
                        case Keyboard::A:
                            Tool::Save("test.txt","Je suis un bel idiot 123456789");
                            break;

                        default:
                            break;
                    }
                    break;

                        default:
                            break;
            }
        }

        window.clear(Color(4,139,154));
        window.display();
    }


    return 0;
}
