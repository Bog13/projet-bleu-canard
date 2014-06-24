#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <typeinfo>
#include <iomanip>
#include <ctime>
#include "core.h"
using namespace std;
using namespace sf;

// \note (Bérenger#3#06/24/14): Petit test.
//test TODO

int main()
{
    RenderWindow window(VideoMode(800,600,64), "PBC",Style::Default);
    window.setFramerateLimit(120);

    srand(time(NULL));
    TextureFactory::load();
    AnimationFactory::load();
    TileFactory::load();
    AreaFactory::load();
    ObjectFactory::load();
    Core core(&window);


    core.run();

    return 0;
}
