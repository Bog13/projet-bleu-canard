#include "animationfactory.h"


vector<Animation> AnimationFactory::m_vector;

void AnimationFactory::load()
{

    {Animation a;a.addFrame(*TextureFactory::getTile(Global::ID_NONE)); m_vector.push_back(a);}
    {Animation a;a.addFrame(*TextureFactory::getTile(Global::ID_GROUND)); m_vector.push_back(a);}
    {Animation a;a.addFrame(*TextureFactory::getTile(Global::ID_GRASS)); m_vector.push_back(a);}
    {Animation a;a.addFrame(*TextureFactory::getTile(Global::ID_ROCK)); m_vector.push_back(a);}

    {Animation a(250);a.addFrame(*TextureFactory::getChar(Global::ID_JOSH,0));a.addFrame(*TextureFactory::getChar(Global::ID_JOSH,2)); m_vector.push_back(a);}



    cout<<"Animations loaded ! "<<endl;
}

Animation AnimationFactory::get(int i)
{
    if(i<m_vector.size() && i>=0)return m_vector[i];
    else cerr<<"ERREUR ANIMATION"<<endl;

}






























AnimationFactory::AnimationFactory()
{
    //ctor
}

AnimationFactory::~AnimationFactory()
{
    //dtor
}
