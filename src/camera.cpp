#include "camera.h"

Camera::Camera(AreaGraphic *ag,Positionable* target): m_ag(ag),VIEW_REFRESH_DELAY(5)
{
    setViewSize(10*Global::TILE_WIDTH, 10*Global::TILE_HEIGHT);
    m_viewX= (ag->getWidth()>>1);
    m_viewY= (ag->getHeight()>>1);
    m_mainView.setSize(m_viewWidth,m_viewHeight);
    m_mainView.setCenter(m_viewX,m_viewY);



    m_viewActivated=true;

    //la vue vaut initialement true pour faire une première mAj
    m_isViewMoving=true;

    m_lastViewMoving=0;

    m_viewSpeed=3* ((Global::TILE_WIDTH+Global::TILE_HEIGHT)>>1);

    m_autoRefresh=60;

    m_target=target;
}



void Camera::setViewPosition (float x, float y)
{
    m_viewX=x;
    m_viewY=y;
}

void Camera::setView(View const &view)
{
    m_mainView=View(view);
}

void Camera::setViewSize(int w,int h)
{
    m_viewWidth=w;
    m_viewHeight=h;
    m_mainView.setSize(m_viewWidth,m_viewHeight);
}

void Camera::moveView(bool right, bool left, bool up, bool down)
{
    const float velocity= static_cast<float>(m_viewSpeed)/static_cast<float>(Global::FPS);

    if( m_viewY + (m_viewHeight>>1)  < m_ag->getHeight()*Global::TILE_HEIGHT )
    {
        moveViewDown( (int)(down)* velocity);
    }

    if( m_viewX- (m_viewWidth>>1) >0)
    {
        moveViewLeft( (int)(left) * velocity);

    }

    if( m_viewX + (m_viewWidth>>1) <m_ag->getWidth()*Global::TILE_WIDTH )
    {
        moveViewRight( (int)(right) * velocity);

    }

    if( m_viewY - (m_viewHeight>>1) >0 )
    {
        moveViewUp((int)(up) * velocity );
    }

}

void Camera::updateViewMoving()
{
    m_isViewMoving=true;
    m_lastViewMoving=-1;
}

void Camera::moveViewUp     (float d)
{
    if(m_viewY-d>=0 && d!=0) {m_viewY-=d;updateViewMoving();}
}
void Camera::moveViewDown   (float d)
{
    if(m_viewY+d>0 && d!=0) {m_viewY+=d;updateViewMoving();}
}
void Camera::moveViewRight  (float d)
{
    if(m_viewX+d>=0 && d!=0 ) {m_viewX+=d;updateViewMoving();}
}
void Camera::moveViewLeft   (float d)
{
    if(m_viewX-d>=0 && d!=0 ) {m_viewX-=d;updateViewMoving();}
}

bool Camera::inView(Positionable* pos)
{
    ///Position de la vue
    float view_x=m_mainView.getCenter().x - (m_mainView.getSize().x/2+Global::TILE_WIDTH);
    float view_y=m_mainView.getCenter().y - (m_mainView.getSize().y/2+Global::TILE_HEIGHT);
    float view_w=m_mainView.getSize().x+Global::TILE_WIDTH;
    float view_h=m_mainView.getSize().y+Global::TILE_HEIGHT;

    ///position du positionnable
    float x=0,y=0,w=0,h=0;
    if(pos!=0)
    {
        x=pos->getX();
        y=pos->getY();
        w=pos->getWidth();
        h=pos->getHeight();
    }else return false;

    return Global::inCollision(x,y,w,h,view_x,view_y,view_w,view_h);
}


bool Camera::inView(Object* obj)
{


    Positionable* pos=0;
    float x=0,y=0,w=0,h=0;

    pos=dynamic_cast<Positionable*>(obj);

    return (inView(pos) && pos!=0 );
}



bool Camera::inView(Movable* m)
{
    Positionable* pos=m->getPos();
    cout << "Perso en x: " << pos->getX() << "   bord gauche de la vue: " << m_mainView.getCenter().x - (m_mainView.getSize().x/2) << endl;
    return inView(pos);
}

bool Camera::inView(float i,float j)
{
    Area* a=m_ag->getArea();

    int vw_w=m_mainView.getSize().x,
        vw_h=m_mainView.getSize().y;

    float  vw_x=m_mainView.getCenter().x,
            vw_y=m_mainView.getCenter().y;

    int offsetDisplay=1;
    int view_height_up= (vw_y- (vw_h>>1) )/Global::TILE_HEIGHT;
    int view_height_down=(vw_y+ (vw_h>>1) )/Global::TILE_HEIGHT+offsetDisplay;
    int view_width_left= (vw_x- (vw_w>>1) )/Global::TILE_WIDTH;
    int view_width_right=(vw_x+ (vw_w>>1) )/Global::TILE_WIDTH+offsetDisplay;

    //on vérifie de rester dans l'écran
    if(view_height_up<0)view_height_up=0;
    if(view_height_down>a->getHeight())view_height_down=a->getHeight();
    if(view_width_left<0)view_width_left=0;
    if(view_width_right>a->getWidth()-1)view_width_right=a->getWidth();

    return (i>= view_height_up && i<=view_height_down && j>=view_width_left && j<=view_width_right);
}

vector<Object*>* Camera::getObjectInView()
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

void Camera::verifyViewInArea()
{
    if(m_viewX- (m_viewWidth>>1) <0) {  m_viewX= (m_viewWidth>>1); }

    if(m_viewX+ (m_viewWidth>>1) > m_ag->getWidth()*Global::TILE_WIDTH )
    {
        m_viewX=m_ag->getWidth()*Global::TILE_WIDTH - (m_viewWidth>>1);
    }

    if(m_viewY- (m_viewHeight>>1) <0) {  m_viewY= (m_viewHeight>>1) ; }

    if(m_viewY+ (m_viewHeight>>1) > m_ag->getHeight()*Global::TILE_HEIGHT)
    {
        m_viewY=m_ag->getHeight()*Global::TILE_HEIGHT - (m_viewHeight>>1);
    }
}

void Camera::setTarget(Positionable* p)
{
    m_target=p;
    m_viewX=p->getX();
    m_viewY=p->getY();

}

void Camera::update(RenderWindow* window)
{

    if( isActivated() )
    {
        if(m_target != NULL  )
        {
            bool u=false,d=false,l=false,r=false;

            if(m_target->getX()> m_viewX+(m_viewWidth>>4) ) r=true;
            if(m_target->getX()< m_viewX-(m_viewWidth>>4) ) l=true;
            if(m_target->getY()< m_viewY-(m_viewHeight>>4) ) u=true;
            if(m_target->getY()> m_viewY+(m_viewHeight>>4) ) d=true;

            moveView(r,l,u,d);

        }

        if( isMoving() )
        {
            verifyViewInArea();
            m_mainView.setCenter(m_viewX,m_viewY);
            window->setView(m_mainView);
            m_isViewMoving=false;
        }

        if(m_lastViewMoving<=VIEW_REFRESH_DELAY+1)m_lastViewMoving++;
    }

}

void Camera::updateAreaTilesInView()
{
    for(int i=(m_viewY- (m_viewHeight>>1) )/Global::TILE_HEIGHT ;i<=(m_viewY+ (m_viewHeight>>1) )/Global::TILE_HEIGHT ;i++)
    {
        for(int j= (m_viewX- (m_viewWidth>>1) )/Global::TILE_WIDTH  ;j<= (m_viewX+ (m_viewWidth>>1) )/Global::TILE_WIDTH;j++)
        {
            if(i>=0 && i<m_ag->getHeight() && j>=0 && j<m_ag->getWidth())
            {
                m_ag->updateTiles(i,j);
            }
        }
    }
}

Camera::~Camera()
{
    //dtor
}
