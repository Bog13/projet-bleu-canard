#include "animationfactory.h"


vector<Animation> AnimationFactory::m_vector;

void AnimationFactory::loadAnimation(int id)
{

    Animation a;
    for (int i(0); i<Global::NB_FRAME_ID[id];i++)
    {
        a.addFrame(*TextureFactory::get(Global::ID[id],i));
        a.setType(id);
    }
    m_vector.push_back(a);



}

void AnimationFactory::load()
{

    for(int i=0;i<Global::NB_TOTAL_ID;i++)
    {
        loadAnimation(i);
    }
    m_vector[PINE_TREE].setDelay(500);


    cout<<"Animations loaded ! "<<endl;
}


/*
bool AnimationFactory::loadAnimation(Animation *a,string fileName)///TODO
{

    fstream file(fileName.c_str(),ios::in);
    int type;
    string line;

    if(file)
    {
        while( getline(file,line) )
        {
            type=Global::strToInt(line);

            a->addFrame(*TextureFactory::get(type));
        }

        cout<<fileName<<" loaded !"<<endl;

    }else cerr<<"Can't load "<<fileName<<" !"<<endl;;
}*/





Animation AnimationFactory::get(unsigned int i)
{
    if(i<m_vector.size() && i>=0){return m_vector[i];}
    else
    {
        cerr<<"ERREUR ANIMATION [AnimFacto::get()] " << i <<endl;
        return m_vector[Global::ID[TILE_NONE]];
    }


}






























AnimationFactory::AnimationFactory()
{
    //ctor
}

AnimationFactory::~AnimationFactory()
{
    //dtor
}
