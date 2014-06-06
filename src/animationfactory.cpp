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

void AnimationFactory::loadAnimation(Animation *a,string fileName)
{
    fstream file(fileName.c_str(),ios::in);
    int type;
    string line;

    if(file)
    {
        while( getline(file,line) )
        {
            type=Global::strToInt(line);

            a->addFrame(*TextureFactory::getTile(type));
        }

        cout<<fileName<<" loaded !"<<endl;

    }else cerr<<"Cant load "<<fileName<<" !"<<endl;;
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
