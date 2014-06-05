#include "animation.h"

Animation::Animation()
{
    init();
}

Animation::Animation(int delay)
{
   init();
   setDelay(delay);
}

void Animation::addFrame(Texture t)
{
    m_textures.push_back(t);
}

void Animation::init()
{
     m_clock.restart();
     m_delay=1000;
     m_running=true;
     m_current=0;

}

Texture* Animation::getCurrentFrame()
{
    if(m_textures.size()>0)
    {
        return &m_textures[m_current];
    }

    cout<<"ERREUR ANIMATION CURRENT FRAME: pas de frame dans l'anim"<<endl;
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