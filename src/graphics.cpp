#include "graphics.h"



Graphics::Graphics(RenderWindow* window,AreaGraphic *ag):m_ag(ag)
{
    m_window=window;
    m_ag->setGraphics(this);
    m_cam=new Camera(m_ag,NULL);
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
    if(a!=0)
    {
        ConvexShape *cs=t->getConvexShape();
        cs->setTexture(a->getCurrentFrame());

        m_window->draw(*cs);
    }
}




void Graphics::drawObjects()
{
    Object *o=0;

    //setVisibleObjects();
/*
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
    */

    for(int i=0;i<m_ag->nbVisibleObject();i++)
    {
        if(m_ag->getVisibleObjectGraphic(i)->hasAnEntity())
        {
            o= dynamic_cast<Object*>( m_ag->getVisibleObjectGraphic(i)->getEntity() );
            if(o != 0)
            {
                m_ag->getVisibleObjectGraphic(i)->getConvexShape()->setPosition(Vector2f(o->getX(),o->getY()));
            }else cerr<<"Erreur conversion object entity (drawObjects)"<<endl;
        }
        else
        {
             m_ag->getVisibleObjectGraphic(i)->getConvexShape()->setPosition(Vector2f(0,0));
             cerr<<"Affichage d'un objet graphique indépendant"<<endl;
        }

        drawEntity(m_ag->getVisibleObjectGraphic(i) );

    }
}









bool Graphics::collideWithObject(int i,int j)
{

    vector<Object*> *vec=m_cam->getObjectInView();
    float objx,objy,objw,objh,x,y,w,h;

    for(int k=0;k<(int)(vec->size());k++)
    {
        objx=(*vec)[k]->getPosition().first;
        objy=(*vec)[k]->getPosition().second;
        objw=(*vec)[k]->getWidth();
        objh=(*vec)[k]->getHeight();
        y=j*Global::TILE_HEIGHT;
        x=i*Global::TILE_WIDTH;
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
    EntityGraphic* e=0;

    const int A=( m_cam->getY() - m_cam->getHH() )/Global::TILE_HEIGHT;
    const int B=( m_cam->getY() + m_cam->getHH() )/Global::TILE_HEIGHT;

    const int C=( m_cam->getX() - m_cam->getHW() )/Global::TILE_WIDTH ;
    const int D=( m_cam->getX() + m_cam->getHW() )/Global::TILE_WIDTH;
    Color c(Global::random(0,255),Global::random(0,255),Global::random(0,255));
    for(int i= A;i<=B ;i++)
    {
        for(int j= C ;j<=D ;j++)
        {
            if(i>=0 && i<m_ag->getHeight() && j>=0 && j<m_ag->getWidth())
            {

                e= m_ag->getTileGraphic(j,i);


                e->getConvexShape()->setPosition(j*Global::TILE_WIDTH,i*Global::TILE_HEIGHT);

                if( (m_cam->isMoving()) || m_cam->wasMoving() || m_cam->mustRefresh() )
                {

                    drawEntity(e);
                    //e->getConvexShape()->setFillColor( c );
                }
                else
                {
                    if( collideWithObject(j,i) )
                    {
                        drawEntity(e);
                        //e->getConvexShape()->setFillColor(c);
                    }


                }

            }

        }
    }


}

void Graphics::drawVisibleAreaUnoptimized()
{
    EntityGraphic* e=0;

    const int A=( m_cam->getY() - m_cam->getHH() )/Global::TILE_HEIGHT;
    const int B=( m_cam->getY() + m_cam->getHH() )/Global::TILE_HEIGHT;

    const int C=( m_cam->getX() - m_cam->getHW() )/Global::TILE_WIDTH ;
    const int D=( m_cam->getX() + m_cam->getHW() )/Global::TILE_WIDTH;
    for(int i= A;i<=B ;i++)
    {
        for(int j= C ;j<=D ;j++)
        {
            if(i>=0 && i<m_ag->getHeight() && j>=0 && j<m_ag->getWidth())
            {

                e= m_ag->getTileGraphic(j,i);


                e->getConvexShape()->setPosition(j*Global::TILE_WIDTH,i*Global::TILE_HEIGHT);

                drawEntity(e);


            }

        }
    }


}



void Graphics::setVisibleObjects()
{
    EntityGraphic* e=0;
    Object* obj=0;

    const int N=m_ag->nbObject();

    for(int i=0;i<N;i++)
    {
        e=m_ag->getObjectGraphic(i);
        obj= dynamic_cast<Object*>(e->getEntity());

        if( m_cam->inView( obj ) )
        {
            e->setVisibility(true);
        }
        else
        {
            e->setVisibility(false);
        }
    }


}

void Graphics::enableCamera(bool b)
{
    m_cam->enableView(b);
}


void Graphics::updateAreaTilesInCamera()
{
    m_cam->updateAreaTilesInView();
}

void Graphics::update()
{
    m_cam->update(m_window);
    if(m_ag->needToResort()){m_ag->sortObj();} ///Littéralement, si y'a besoin on tri, défini dans AreaGraphic::updateVisibleObject(unsigned int i)

}

Graphics::~Graphics()
{
    delete m_cam;
}
