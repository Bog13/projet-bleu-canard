#include "animation.h"

Animation::Animation(int t):Typable(t)
{
    init();
}



Animation::Animation(int t,int delay):Typable(t)
{
   init();
   setDelay(delay);
}

void Animation::setCurrentFrame(int i)
{
    if(m_textures.size()>1)
    {
        m_current=i;
        m_current%=m_textures.size();
    }
}

void Animation::addFrame(Texture t)
{
    m_textures.push_back(t);
}

void Animation::init()
{
     m_clock.restart();
     m_delay=100;
     m_running=true;
     m_current=0;

}

Texture* Animation::getCurrentFrame()
{
    if(m_textures.size()>0)
    {
        return &m_textures[m_current];
    }

    else {cout<<"ERREUR ANIMATION CURRENT FRAME: pas de frame dans l'anim"<<endl; return 0;}
}

Texture* Animation::getFrame(int i)
{
    if(i>=0 &&i<(int)(m_textures.size()))
    {
        return &m_textures[m_current];
    }

    else{cout<<"ERREUR ANIMATION FRAME: "<<i<<" !"<<endl;return 0;}
}

bool Animation::operator ==(Animation a)
{
    for (int i(0); i<a.nbFrame() || i<(int)(m_textures.size());i++)
    {
        if (getFrame(i)!=a.getFrame(i)) {return false;}
    }
    return true;
}

void Animation::play()
{
    m_running=true;
}

void Animation::stop()
{
    m_running=false;
}

void Animation::update()
{

    if(m_running && m_textures.size()>1)
    {
        if(m_clock.getElapsedTime().asMilliseconds()>= m_delay)
        {
            m_current++;
            m_current%=m_textures.size();

             m_clock.restart();

        }
    }
}

void Animation::setDelay(int delay)
{
    if(delay>0)
    {
        m_delay=delay;
    }else m_delay=1000;
}

Animation::~Animation()
{
    //dtor
}
