#include "keyboardcontroller.h"

KeyboardController::KeyboardController():Controller()
{
    //ctor
}


bool KeyboardController::up()
{

    if(Keyboard::isKeyPressed(Keyboard::Z))return true;
    return false;
}

bool KeyboardController::down()
{
    if(Keyboard::isKeyPressed(Keyboard::S))return true;
    return false;
}

bool KeyboardController::left()
{
    if(Keyboard::isKeyPressed(Keyboard::Q))return true;
    return false;
}

bool KeyboardController::right()
{
    if(Keyboard::isKeyPressed(Keyboard::D))return true;
    return false;
}


bool KeyboardController::yes()
{
    if(Keyboard::isKeyPressed(Keyboard::Space))return true;
    return false;
}

bool KeyboardController::no()
{
    if(Keyboard::isKeyPressed(Keyboard::LControl))return true;
    return false;
}


bool KeyboardController::noOp()
{
    return ( !up()&&!down()&&!left()&&!right()&&!no()&&!yes() );
}


KeyboardController::~KeyboardController()
{
    //dtor
}
