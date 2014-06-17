#include "player.h"

Player::Player(Area *a, Controller* c):Controlable(c), Movable(this),Object(a)
{
    init();
}

void Player::init()
{
    m_speed=pair<float,float>(0.25,0.25);
}

Player::Player(Area *a, Controller* c, int type,float x, float y,float w,float h,bool obs): Controlable(c),Object(a,type,x,y,w,h,obs), Movable(this)
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
    Object::update();
    updateControlable();


}

Player::~Player()
{
    //dtor
}
