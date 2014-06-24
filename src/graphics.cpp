#include "graphics.h"



Graphics::Graphics(RenderWindow* window,AreaGraphic *ag): VIEW_REFRESH_DELAY(5)
{
    m_window=window;
    m_ag=ag;

     ///View
    setViewSize(10*Global::TILE_WIDTH, 10*Global::TILE_HEIGHT);
    m_viewX=300;
    m_viewY=300;
    m_mainView.setSize(m_viewWidth,m_viewHeight);
    m_mainView.setCenter(m_viewX,m_viewY);

    m_window->setView(m_mainView);

    m_viewActivated=true;

    //la vue vaut initialement true pour faire une première mAj
    m_isViewMoving=true;

    m_lastViewMoving=false;
    m_viewSpeed=7* (Global::TILE_WIDTH+Global::TILE_HEIGHT)/2;
    m_autoRefresh=60;
    ///


}

void Graphics::setViewSize(int w,int h)
{
    m_viewWidth=w;
    m_viewHeight=h;
    m_mainView.setSize(m_viewWidth,m_viewHeight);
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




void Graphics::drawObjects()
{
    Object *o=0;

    setVisibleObjects();

    for(int i=0;i<m_ag->nbObject();i++)
    {
        if(m_ag->getObjectGraphic(i)->hasAnEntity())
        {
            o= dynamic_cast<Object*>( m_ag->getObjectGraphic(i)->getEntity() );
            if(o != 0)
            {
                m_ag->getObjectGraphic(i)->getConvexShape()->setPosition(Vector2f(o->getX(),o->getY()));
            }else cerr<<"Erreur conversion object entity (drawObjects)"<<endl;
        }
        else
        {
             m_ag->getObjectGraphic(i)->getConvexShape()->setPosition(Vector2f(0,0));
             cerr<<"Affichage d'un objet graphique indépendant"<<endl;
        }

        if( m_ag->getObjectGraphic(i)->isVisible() )
        {
            drawEntity(m_ag->getObjectGraphic(i) );
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



vector<Object*>* Graphics::getObjectInView()
{
    vector<Object*>* vec=new vector<Object*>();
    Area *a=m_ag->getArea();

    for(int i=0;i<a->nbObject();i++)
    {


        if( inView( a->getObject(i) ) )
        {
            vec->push_back( a->getObject(i) );
        }

    }
    return vec;
}

bool Graphics::collideWithObject(int i,int j)
{

    vector<Object*> *vec=getObjectInView();
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

void Graphics::drawVisibleArea()
{

    Area* a=m_ag->getArea();
    setVisibleEntities();
    EntityGraphic* e=0;

    for(int i=0;i<a->getHeight();i++)
    {
        for(int j=0;j<a->getWidth();j++)
        {
            e= m_ag->getTileGraphic(j,i);

            if( e->isVisible() )
            {
                e->getConvexShape()->setPosition(j*Global::TILE_WIDTH,i*Global::TILE_HEIGHT);

                if( (m_isViewMoving) || (m_lastViewMoving<=VIEW_REFRESH_DELAY)   || time(NULL)%m_autoRefresh==0)
                {
                     drawEntity(e);

                }
                else
                {
                    if( collideWithObject(i,j) )
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


void Graphics::moveView(bool right, bool left, bool up, bool down)
{

    if( m_viewY + m_viewHeight/2  < m_ag->getHeight()*Global::TILE_HEIGHT )moveViewDown( (int)(down)* (m_viewSpeed/Global::FPS));
    if( m_viewX-m_viewWidth/2 >0) moveViewLeft( (int)(left) * (m_viewSpeed/Global::FPS));
    if( m_viewX + m_viewWidth/2<m_ag->getWidth()*Global::TILE_WIDTH ) moveViewRight( (int)(right) * (m_viewSpeed/Global::FPS));
    if( m_viewY - m_viewHeight/2 >0 ) moveViewUp((int)(up) * (m_viewSpeed/Global::FPS) );

}

void Graphics::updateViewMoving()
{
    m_isViewMoving=true;
    m_lastViewMoving=0;
}

void Graphics::moveViewUp     (float d)
{
    if(m_viewY-d>=0 && d!=0) {m_viewY-=d;updateViewMoving();}
}
void Graphics::moveViewDown   (float d) ///Besoin d'une valeur max, en attendant illimité
{
    if(m_viewY+d>0 && d!=0) {m_viewY+=d;updateViewMoving();}
}
void Graphics::moveViewRight  (float d)
{
    if(m_viewX+d>=0 && d!=0 ) {m_viewX+=d;updateViewMoving();}
}
void Graphics::moveViewLeft   (float d)
{
    if(m_viewX-d>=0 && d!=0 ) {m_viewX-=d;updateViewMoving();}
}

bool Graphics::inView(float i,float j)
{
    Area* a=m_ag->getArea();

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

void Graphics::setVisibleObjects()
{
    Area* a=m_ag->getArea();
    EntityGraphic* e=0;
    Object* obj=0;


    for(int i=0;i<m_ag->nbObject();i++)
    {
        e=m_ag->getObjectGraphic(i);
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

void Graphics::setVisibleEntities()
{

    Area* a=m_ag->getArea();

    EntityGraphic* e=0;


    for(int i=0;i<a->getHeight();i++)
    {
        for(int j=0;j<a->getWidth();j++)
        {
            e= m_ag->getTileGraphic(j,i);

            if(inView(i,j))
            {
                e->setVisibility(true);
            }
            else
            {
                e->setVisibility(false);
            }
        }
    }

    /*for(int i=(m_viewY-m_viewHeight/2)/Global::TILE_HEIGHT +2;i<(m_viewY+m_viewHeight/2)/Global::TILE_HEIGHT -2 ;i++)
    {
        for(int j= (m_viewX-m_viewWidth/2)/Global::TILE_WIDTH +2 ;j< (m_viewX+m_viewWidth/2)/Global::TILE_WIDTH-2;j++)
        {
            e= m_ag->getTileGraphic(j,i);
            e->setVisibility(true);
            e->getConvexShape()->setFillColor(c);
        }
    }*/

}
/// ///////////////FIN VUE//////////////////////////

void Graphics::verifyViewInArea()
{
    if(m_viewX-m_viewWidth/2 <0) {  m_viewX=m_viewWidth/2; }

    if(m_viewX+m_viewWidth/2 > m_ag->getWidth()*Global::TILE_WIDTH )
    {
        m_viewX=m_ag->getWidth()*Global::TILE_WIDTH - m_viewWidth/2;
    }

    if(m_viewY-m_viewHeight/2 <0) {  m_viewY=m_viewHeight/2; }

    if(m_viewY+m_viewHeight/2 > m_ag->getHeight()*Global::TILE_HEIGHT)
    {
        m_viewY=m_ag->getHeight()*Global::TILE_HEIGHT - m_viewHeight/2;
    }
}

void Graphics::update()
{

    if(m_viewActivated)
    {
        if(m_isViewMoving)
        {
            verifyViewInArea();
            m_mainView.setCenter(m_viewX,m_viewY);
            m_window->setView(m_mainView);
            m_isViewMoving=false;
        }

        m_lastViewMoving++;


    }
    else{m_window->setView(m_window->getDefaultView());}
}

Graphics::~Graphics()
{
    //dtor
}
