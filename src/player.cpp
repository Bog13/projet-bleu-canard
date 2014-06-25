#include "player.h"

Player::Player(Area *a, Controller* c):Object(a),Controlable(c), Movable(this,this)
{
    init();
}

void Player::init()
{
    m_absoluteSpeed=pair<float,float>(3*Global::TILE_WIDTH,2*Global::TILE_HEIGHT);

    setHitbox(0,(3/4.)*getHeight(),getWidth(),(1/4.)*getHeight());
}

Player::Player(Area *a, Controller* c, int type,float x, float y,float w,float h,bool obs): Object(a,type,x,y,w,h,obs),Controlable(c), Movable(this,this)
{
    init();
}

void Player::updateControlable()
{
    Controlable::updateControlable();

    if(m_controller->noOp() )
    {
    }
    else
    {
        if(m_controller->up())moveUp();
        if(m_controller->down())moveDown();
        if(m_controller->left())moveLeft();
        if(m_controller->right())moveRight();
        if(m_controller->yes()){}
        if(m_controller->no()){}
    }
}

void Player::update()
{
    updateMovable();
    Object::update();
    updateControlable();


}

Player::~Player()
{
    //dtor
}
