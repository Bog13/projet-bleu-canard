#include "jostickcontroller.h"

JostickController::JostickController()
{
    //m_loaded=Jostick::isConnected(0);
}

bool JostickController::up()
{

    if(true)return true;
    return false;
}

bool JostickController::down()
{
    if(true)return true;
    return false;
}

bool JostickController::left()
{
    if(true)return true;
    return false;
}

bool JostickController::right()
{
    if(true)return true;
    return false;
}


bool JostickController::yes()
{
    if(true)return true;
    return false;
}

bool JostickController::no()
{
    if(true)return true;
    return false;
}


bool JostickController::noOp()
{
    return ( !up()&&!down()&&!left()&&!right()&&!no()&&!yes() );
}


JostickController::~JostickController()
{
    //dtor
}
