#include <iostream>
#include "../include/tool.h"
#include "../include/global.h"
#include "../include/area.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


ConvexShape* createConvex(int x,int y,int w,int h);

/** Crée un convexShape de la forme d'une Tile**/
ConvexShape* createConvex(int x,int y,int w,int h)
{
    ConvexShape* shape=new ConvexShape(4);
    ///Variables pour raccourcir l'écriture
    float   width=Global::TILE_WIDTH,
            height=Global::TILE_HEIGHT;
    ///

    shape->setPoint(0,Vector2f(0,0));

    shape->setPoint(1,Vector2f(width,0));
    shape->setPoint(2,Vector2f(width,height));
    shape->setPoint(3,Vector2f(0,height));

    shape->setOrigin(0,height); ///IMPORTANT: le coin en inf.gauche DOIT être l'origine pour l'affichage via Tool::toOrtho()
    shape->setFillColor(Color::White);
    shape->setOutlineThickness(2);
    shape->setOutlineColor(Color::Red);
    shape->setPosition(Tool::toOrthoX(x),Tool::toOrthoY(y));

    return shape;

}


ConvexShape* toIsoConvex(ConvexShape* cs)
{
    float x=0,
        y=0,
        isoX=0,
        isoY=0;

    for(int i=0;i<cs->getPointCount();i++)
    {
        x=cs->getPoint(i).x;
        y=cs->getPoint(i).y;

        cs->setPoint(i,Vector2f(Tool::toIso(x,y).first,
                               Tool::toIso(x,y).second));

    }

    cs->setOrigin(Vector2f(0,Global::TILE_HEIGHT));
    x= cs->getPosition().x;
    y=cs->getPosition().y;

    isoX=Tool::toIso(x,y).first;
    isoY=Tool::toIso(x,y).second;

    cs->setPosition(Vector2f(isoX,isoY + Global::WINDOW_HEIGHT ));

    return cs;
}



ConvexShape* createIsoConvex(int x,int y,int w,int h)
{
    /** Methode qui abrège l'affichage, ca crée un convexshape déjà sous forme iso. **/

    ConvexShape* shape= toIsoConvex( createConvex(x,y,w,h) );


    //shape= *(toIsoConvex(&);


    /// Pour l'affichage, il nous faut encore déterminer l'origine de ce shape, j'ai pas trouvé à l'instinct.
    /*shape.setFillColor(Color::White);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(Color::Red);*/

    //shape.setPosition(Tool::toOrthoX(x),Tool::toOrthoY(y));

    //shape.setPosition(x,y);
    return shape;

}



void display(Area* area,RenderWindow* window)
{
    /** N'utilise pas encore l'area mais fonctionnel pour des simples tiles **/
    for(int i=0;i<Global::NB_TILE_HEIGHT;i++)
    {
        for(int j=0;j<Global::NB_TILE_WIDTH;j++)
        {
            ConvexShape* myTile=createConvex(j*Global::TILE_HEIGHT,i*Global::TILE_WIDTH,Global::TILE_WIDTH,Global::TILE_HEIGHT);
            window->draw(*myTile);
        }
    }
}

void displayIso(Area* area,RenderWindow* window)
{
    ConvexShape* myTile=0;

    float   width=Global::TILE_WIDTH,
            height=Global::TILE_HEIGHT;

    float x=0,
          y=0;


    for(int i=0;i<Global::NB_TILE_HEIGHT;i++)
    {
        for(int j=0;j<Global::NB_TILE_WIDTH;j++)
        {
            x=j*Global::TILE_HEIGHT;
            y=i*Global::TILE_WIDTH;

            myTile=createIsoConvex(x,y,width,height);
            window->draw(*myTile);
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

        displayIso(&currentArea, &window);
        /*window.draw(createIsoConvex(200,                //x
                                    200,                //y
                                    Global::TILE_WIDTH, //width
                                    Global::TILE_HEIGHT));//height*/

        window.display();
    }


    return 0;
}
