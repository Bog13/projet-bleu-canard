#include <iostream>
#include "../include/tool.h"
#include "../include/global.h"
#include "../include/area.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


ConvexShape createConvex(int x,int y,int w,int h)
/** Crée un convexShape de la forme d'une Tile**/
{
    ConvexShape shape(4);
    ///Variables pour raccourcir l'écriture
    float   width=Global::TILE_WIDTH,
            height=Global::TILE_HEIGHT;
    ///


    shape.setPoint(0,Vector2f(0,0));
    shape.setPoint(1,Vector2f(width,0));
    shape.setPoint(2,Vector2f(width,height));
    shape.setPoint(3,Vector2f(0,height));

    shape.setOrigin(0,height); ///IMPORTANT: le coin en inf.gauche DOIT être l'origine pour l'affichage via Tool::toOrtho()
    shape.setFillColor(Color::White);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(Color::Red);
    shape.setPosition(Tool::toOrthoX(x),Tool::toOrthoY(y));

    return shape;

}


ConvexShape createIsoConvex(int x,int y,int w,int h)
{
    /** Methode qui abrège l'affichage, ca crée un convexshape déjà sous forme iso. **/

    ConvexShape shape(4);
    ///Variables pour raccourcir l'écriture
    float   width=Global::TILE_WIDTH,
            height=Global::TILE_HEIGHT;
    ///

    shape.setPoint(0,Vector2f(Tool::toIso(0,0).first,
                              Tool::toIso(0,0).second));
    shape.setPoint(1,Vector2f(Tool::toIso(width,0).first,
                              Tool::toIso(width,0).second));
    shape.setPoint(2,Vector2f(Tool::toIso(width,-height).first,
                              Tool::toIso(width,-height).second));
    shape.setPoint(3,Vector2f(Tool::toIso(0,-height).first,
                              Tool::toIso(0,-height).second));


    /// Pour l'affichage, il nous faut encore déterminer l'origine de ce shape, j'ai pas trouvé à l'instinct.
    shape.setFillColor(Color::White);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(Color::Red);
    shape.setPosition(Tool::toOrthoX(x),Tool::toOrthoY(y));

    return shape;

}


void display(Area* area,RenderWindow* window)
{
    /** A revoir entièrement car n'utilise pas l'area **/
    for(int i=0;i<Global::NB_TILE_HEIGHT;i++)
    {
        for(int j=0;j<Global::NB_TILE_WIDTH;j++)
        {
            ConvexShape myTile=createConvex(j*Global::TILE_HEIGHT,i*Global::TILE_WIDTH,Global::TILE_WIDTH,Global::TILE_HEIGHT);

            window->draw(myTile);
        }
    }
}

void displayIso(Area* area,RenderWindow* window)
{
    /** A refaire totalement car n'utilise pas l'area.
    Pour le moment, ca crée un ConvexIsoShape et l'affiche au bon endroit. **/
    for(int i=0;i<Global::NB_TILE_HEIGHT;i++)
    {
        for(int j=0;j<Global::NB_TILE_WIDTH;j++)
        {
            ConvexShape myTile=createIsoConvex(j*Global::TILE_HEIGHT,i*Global::TILE_WIDTH,Global::TILE_WIDTH,Global::TILE_HEIGHT);

            window->draw(myTile);
        }
    }
}



int main()
{

    RenderWindow window(VideoMode(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT),"Test");
    Event event;
    Area currentArea;

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

                        default:
                            break;
                    }
                    break;

                        default:
                            break;
            }
        }

        window.clear(Color(4,139,154));
        //displayIso(&currentArea, &window);
        window.draw(createIsoConvex(200,                //x
                                    200,                //y
                                    Global::TILE_WIDTH, //width
                                    Global::TILE_HEIGHT));//height
        window.display();
    }


    return 0;
}
