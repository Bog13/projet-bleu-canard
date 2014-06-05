#include "graphics.h"

Graphics::Graphics(RenderWindow* window)
{
    m_window=window;

     //View
    m_viewWidth=10*Global::TILE_WIDTH;
    m_viewHeight=10*Global::TILE_HEIGHT;
    m_viewPositionX=0;
    m_viewPositionY=0;
    m_mainView.setSize(m_viewWidth,m_viewHeight);
    m_mainView.setCenter(m_viewPositionX,m_viewPositionY);
    m_viewActivated=false;

}



ConvexShape Graphics::createSquare(int x,int y,int w,int h)
{
    //ConvexShape
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

/*void Graphics::drawCharacter(CharacterGraphic c)
{
    Animation a=*c.getAnimation();
    ConvexShape cs=*c.getConvexShape();
    cs.setTexture(a.getCurrentFrame());


    m_window->draw(cs);
}*/

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

/** Controle de la vue principale **/

void Graphics::enableView(bool b)
{
    m_viewActivated=b;

}

void Graphics::setViewPosition (float x, float y)
{
    m_viewPositionX=x;
    m_viewPositionY=y;
}


void Graphics::moveView(float right, float left, float up, float down)
{
    moveViewDown(down);
    moveViewLeft(left);
    moveViewRight(right);

}

void Graphics::moveViewUp     (float d)
{
    if(m_viewPositionY-d>=0) {m_viewPositionY-=d;}
}
void Graphics::moveViewDown   (float d) ///Besoin d'une valeur max, en attendant illimité
{
    if(m_viewPositionY+d>0) {m_viewPositionY+=d;}
}
void Graphics::moveViewRight  (float d)
{
    if(m_viewPositionX+d>=0) {m_viewPositionX+=d;}
}
void Graphics::moveViewLeft   (float d)
{
    if(m_viewPositionX-d>=0) {m_viewPositionX-=d;}
}
/// ///////////////////////////////////////////////////

void Graphics::update()
{
    if(m_viewActivated)
        {
            m_mainView.setCenter(m_viewPositionX,m_viewPositionY);
            m_window->setView(m_mainView);
        }
    else                {m_window->setView(m_window->getDefaultView());}
}

Graphics::~Graphics()
{
    //dtor
}
