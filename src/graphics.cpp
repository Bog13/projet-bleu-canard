#include "graphics.h"

Graphics::Graphics(RenderWindow* window)
{
    m_window=window;
}



ConvexShape Graphics::createSquare(int x,int y,int w,int h)
{
    ConvexShape cs(4);
    cs.setPoint(0,Vector2f(0,0));
    cs.setPoint(1,Vector2f(w,0));
    cs.setPoint(2,Vector2f(w,h));
    cs.setPoint(3,Vector2f(0,h));

    cs.setOutlineColor(Color::Black);
    cs.setOutlineThickness(1.);

    cs.setFillColor(Color::White);

    cs.setPosition(Vector2f(x,y));

    return cs;
}

void Graphics::drawTile(TileGraphic t)
{
    Animation a=*t.getAnimation();
    ConvexShape cs=*t.getConvexShape();
    cs.setTexture(a.getCurrentFrame());

    m_window->draw(cs);
}

void Graphics::drawArea(AreaGraphic *ag)
{

    for(int i=0;i<ag->getHeight();i++)
    {
        for(int j=0;j<ag->getWidth();j++)
        {
            ag->getTileGraphic(j,i)->getConvexShape()->setPosition(Vector2f(j*Global::TILE_WIDTH,i*Global::TILE_HEIGHT));
            drawTile(*ag->getTileGraphic(j,i));
        }
    }
}

Graphics::~Graphics()
{
    //dtor
}
