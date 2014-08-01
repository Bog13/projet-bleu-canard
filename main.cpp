#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <typeinfo>
#include <iomanip>

#include <ctime>
#include "core.h"
#include "global.h"
#include "graphics.h"

#include "tilefactory.h"
#include "texturefactory.h"
#include "areafactory.h"
#include "animationfactory.h"
#include "objectfactory.h"

using namespace std;
using namespace sf;

#define INT_MAX 100000
/*TEST bog commit de l'amour */
// Iam a duck with a gun in his hair <3 
int main()
{

    srand(time(NULL));

    RenderWindow window(VideoMode(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT,64), "PROJECT BLUE DUCK",Style::Default);

    ///loading Screen
    Texture texture;
    texture.loadFromFile(Global::PATH_IMG+"loading.png");

    ConvexShape cs=Graphics::createSquare(0,0,Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT);

    cs.setTexture(&texture);
    window.draw(cs);
    window.display();
    ///



    ///Loading

    TextureFactory::load();
    AnimationFactory::load();
    TileFactory::load();
    AreaFactory::load();
    ObjectFactory::load();
    ///

    Core core(&window);


   core.run();

    return 0;
}
