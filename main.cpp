#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "core.h"
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800,600,64), "test");

    TextureFactory::load();
    AnimationFactory::load();
    TileFactory::load();
    AreaFactory::load();

    Core core(&window);
    core.run();

    return 0;
}
