#include "animationfactory.h"


vector<Animation> AnimationFactory::m_vector;

void AnimationFactory::load()
{
    ///NONE
    {Animation a;a.addFrame(*TextureFactory::get(Global::ID_NONE)); m_vector.push_back(a);}

    ///HIGHT GRASS
    {Animation a;
    for(int i(0); i<Global::NB_STATE_HIGHT_GRASS;i++) ///4 frames
    {
        a.addFrame(*TextureFactory::get(Global::ID_TEXTURE_HIGHT_GRASS+i));
    }
    m_vector.push_back(a);}

    ///HIGHT_GRASS_tGROUND
    for (int i(0); i<Global::NB_STATE_HIGHT_GRASS_tGROUND;i++) ///4 textures
    {
    {Animation a;a.addFrame(*TextureFactory::get(Global::ID_TEXTURE_HIGHT_GRASS_tGROUND+i)); m_vector.push_back(a);}
    }

    ///DESERT
    {Animation a;
    for(int i(0); i<Global::NB_STATE_DESERT;i++)    ///7 frames
    {
        a.addFrame(*TextureFactory::get(Global::ID_TEXTURE_DESERT+i));
    }
    m_vector.push_back(a);}

    ///SNOW
    for (int i(0); i<Global::NB_STATE_SNOW;i++) ///5 textures
    {
        {Animation a;a.addFrame(*TextureFactory::get(Global::ID_TEXTURE_SNOW+i)); m_vector.push_back(a);}
    }

    for (int i(0); i<Global::NB_STATE_CHAR_NONE;i++) ///5 textures
    {
        {Animation a;a.addFrame(*TextureFactory::get(Global::ID_CHAR_NONE+i)); m_vector.push_back(a);}
    }


    /*Qu'est-ce que c'est ça ? C'est pas moi je crois.
    {
        Animation a(125);
        a.addFrame(*TextureFactory::get(Global::ID_CHAR_NONE));
        a.addFrame(*TextureFactory::get(Global::ID_CHAR_NONE+1));
        a.addFrame(*TextureFactory::get(Global::ID_CHAR_NONE+2));

        m_vector.push_back(a);
    }*/



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

            a->addFrame(*TextureFactory::get(type));
        }

        cout<<fileName<<" loaded !"<<endl;

    }else cerr<<"Can't load "<<fileName<<" !"<<endl;;
}



Animation AnimationFactory::get(int i)
//Plus sû maintenant
{
    if(i<m_vector.size() && i>=0)return m_vector[i];
    else cerr<<"ERREUR ANIMATION [AnimFacto::get()] " << i <<endl;

}






























AnimationFactory::AnimationFactory()
{
    //ctor
}

AnimationFactory::~AnimationFactory()
{
    //dtor
}
