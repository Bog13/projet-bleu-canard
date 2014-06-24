#include "graphics.h"

Graphics::Graphics(RenderWindow* window)
{
    m_window=window;

     //View

    m_viewWidth=10*Global::TILE_WIDTH;
    m_viewHeight=10*Global::TILE_HEIGHT;
    m_viewX=0;
    m_viewY=0;
    m_mainView.setSize(m_viewWidth,m_viewHeight);
    m_mainView.setCenter(m_viewX,m_viewY);
    m_viewActivated=true;
    m_isViewMoving=false;

    m_window->setView(m_mainView);

}

void Graphics::setViewSize(int w,int h)
{
    m_mainView.setSize(w,h);
}



ConvexShape Graphics::createSquare(int x,int y,int w,int h)
{
    //ConvexShape
    ConvexShape cs(4);
    cs.setPoint(0,Vector2f(0,0));
    cs.setPoint(1,Vector2f(w,0));
    cs.setPoint(2,Vector2f(w,h));
    cs.setPoint(3,Vector2f(0,h));

    ///Désactivés pour le visuel, peut-être remis librement.
    //cs.setOutlineColor(Color::Black);
    //cs.setOutlineThickness(1.);

    cs.setFillColor(Color::White);

    cs.setPosition(Vector2f(x,y));




    return cs;
}

void Graphics::drawEntity(EntityGraphic *t)
{
    Animation *a=t->getAnimation();
    ConvexShape *cs=t->getConvexShape();
    cs->setTexture(a->getCurrentFrame());

    m_window->draw(*cs);
}


void Graphics::drawArea(AreaGraphic *ag)
{

    for(int i=0;i<ag->getHeight();i++)
    {
        for(int j=0;j<ag->getWidth();j++)
        {
            ag->getTileGraphic(j,i)->getConvexShape()->setPosition(Vector2f(j*Global::TILE_WIDTH,i*Global::TILE_HEIGHT));
            drawEntity(ag->getTileGraphic(j,i));
        }
    }

    drawObjects(ag);

}

void Graphics::drawObjects(AreaGraphic *ag)
{
    Object *o=0;

    setVisibleObjects(ag);

    for(int i=0;i<ag->nbObject();i++)
    {
        if(ag->getObjectGraphic(i)->hasAnEntity())
        {
            o= dynamic_cast<Object*>( ag->getObjectGraphic(i)->getEntity() );
            if(o != 0)
            {
                ag->getObjectGraphic(i)->getConvexShape()->setPosition(Vector2f(o->getX(),o->getY()));
            }else cerr<<"Erreur conversion object entity (drawObjects)"<<endl;
        }
        else
        {
             ag->getObjectGraphic(i)->getConvexShape()->setPosition(Vector2f(0,0));
             cerr<<"Affichage d'un objet graphique indépendant"<<endl;
        }

        if( ag->getObjectGraphic(i)->isVisible() )
        {
            drawEntity(ag->getObjectGraphic(i) );
        }
    }
}

void Graphics::setView(View const &view)
{
    m_mainView=View(view);
}

bool Graphics::inView(Object* obj)
{
    float view_x=m_mainView.getCenter().x - m_mainView.getSize().x/2;
    float view_y=m_mainView.getCenter().y - m_mainView.getSize().y/2;
    float view_w=m_mainView.getSize().x;
    float view_h=m_mainView.getSize().y;

    Positionable* pos=0;
    float x=0,y=0,w=0,h=0;

    pos=dynamic_cast<Positionable*>(obj);
    if(pos!=0)
    {
        x=pos->getX();
        y=pos->getY();
        w=pos->getWidth();
        h=pos->getHeight();
    }else return false;

    return (x+w>=view_x && x<=view_x+view_w && y+h>=view_y && y<=view_y+view_h);
}



vector<Object*>* Graphics::getObjectInView(AreaGraphic* ag)
{
    vector<Object*>* vec=new vector<Object*>();
    Area *a=ag->getArea();

    for(int i=0;i<a->nbObject();i++)
    {


        if( inView( a->getObject(i) ) )
        {
            vec->push_back( a->getObject(i) );
        }

    }
    return vec;
}

bool Graphics::collideWithObject(int i,int j,AreaGraphic* ag)
{

    vector<Object*> *vec=getObjectInView(ag);
    float objx,objy,objw,objh,x,y,w,h;

    for(int k=0;k<vec->size();k++)
    {
        objx=(*vec)[k]->getPosition().first;
        objy=(*vec)[k]->getPosition().second;
        objw=(*vec)[k]->getWidth();
        objh=(*vec)[k]->getHeight();
        y=i*Global::TILE_WIDTH;
        x=j*Global::TILE_HEIGHT;
        w=Global::TILE_WIDTH;
        h=Global::TILE_HEIGHT;


        if( !( x>objx+objw || x+w < objx || y> objy+objh || y+h<objy ) )
        {
            return true;
        }



    }
    return false;

}

void Graphics::drawVisibleArea(AreaGraphic *ag)
{

    Area* a=ag->getArea();
    setVisibleEntities(ag);
    EntityGraphic* e=0;

    for(int i=0;i<a->getHeight();i++)
    {
        for(int j=0;j<a->getWidth();j++)
        {
            e= ag->getTileGraphic(j,i);

            if( e->isVisible() )
            {
                e->getConvexShape()->setPosition(j*Global::TILE_WIDTH,i*Global::TILE_HEIGHT);

                if(m_isViewMoving)
                {
                     drawEntity(e);
                }
                else
                {
                    if( collideWithObject(i,j,ag) )
                    {
                        drawEntity(e);
                    }
                }

            }
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
    m_viewX=x;
    m_viewY=y;
}


void Graphics::moveView(float right, float left, float up, float down)
{
    moveViewDown(down);
    moveViewLeft(left);
    moveViewRight(right);
    moveViewUp(up);

}

void Graphics::moveViewUp     (float d)
{
    if(m_viewY-d>=0) {m_viewY-=d;m_isViewMoving=true;}
}
void Graphics::moveViewDown   (float d) ///Besoin d'une valeur max, en attendant illimité
{
    if(m_viewY+d>0) {m_viewY+=d;m_isViewMoving=true;}
}
void Graphics::moveViewRight  (float d)
{
    if(m_viewX+d>=0) {m_viewX+=d;m_isViewMoving=true;}
}
void Graphics::moveViewLeft   (float d)
{
    if(m_viewX-d>=0) {m_viewX-=d;m_isViewMoving=true;}
}

bool Graphics::inView(AreaGraphic *ag, float i,float j)
{
    Area* a=ag->getArea();

    int vw_w=m_mainView.getSize().x,
        vw_h=m_mainView.getSize().y;

    float  vw_x=m_mainView.getCenter().x,
            vw_y=m_mainView.getCenter().y;

    Vector2f center=m_mainView.getCenter();
    int offsetDisplay=1;
    int view_height_up= (vw_y-vw_h/2)/Global::TILE_HEIGHT;
    int view_height_down=(vw_y+vw_h/2)/Global::TILE_HEIGHT+offsetDisplay;
    int view_width_left= (vw_x-vw_w/2)/Global::TILE_WIDTH;
    int view_width_right=(vw_x+vw_w/2)/Global::TILE_WIDTH+offsetDisplay;

    //on vérifie de rester dans l'écran
    if(view_height_up<0)view_height_up=0;
    if(view_height_down>a->getHeight())view_height_down=a->getHeight();
    if(view_width_left<0)view_width_left=0;
    if(view_width_right>a->getWidth()-1)view_width_right=a->getWidth();

    return (i>= view_height_up && i<=view_height_down && j>=view_width_left && j<=view_width_right);
}

void Graphics::setVisibleObjects(AreaGraphic *ag)
{
    Area* a=ag->getArea();
    EntityGraphic* e=0;
    Object* obj=0;


    for(int i=0;i<ag->nbObject();i++)
    {
        e=ag->getObjectGraphic(i);
        obj= dynamic_cast<Object*>(e->getEntity());

        if( inView( obj ) )
        {
            e->setVisibility(true);
        }
        else
        {
            e->setVisibility(false);
        }
    }


}

void Graphics::setVisibleEntities(AreaGraphic *ag)
{
    Area* a=ag->getArea();
    EntityGraphic* e=0;


    for(int i=0;i<a->getHeight();i++)
    {
        for(int j=0;j<a->getWidth();j++)
        {
            e= ag->getTileGraphic(j,i);

            if(inView(ag,i,j))
            {
                e->setVisibility(true);
            }
            else
            {
                e->setVisibility(false);
            }
        }
    }
}
/// ///////////////FIN VUE//////////////////////////

void Graphics::update()
{

    if(m_viewActivated)
    {
        if(m_isViewMoving)
        {
            m_mainView.setCenter(m_viewX,m_viewY);
            m_window->setView(m_mainView);

        }
        //m_window->setView(m_mainView);


        m_isViewMoving=false;
    }
    else{m_window->setView(m_window->getDefaultView());}
}

Graphics::~Graphics()
{
    //dtor
}
