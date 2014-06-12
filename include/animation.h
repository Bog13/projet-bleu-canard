#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Animation
{
    public:
        Animation();
        Animation(int delay);
        void play();
        void stop();
        void setDelay(int delay);
        void addFrame(Texture t);
        int nbFrame(){return m_textures.size();}
        void init();
        void update();
        Texture* getCurrentFrame();
        void setCurrentFrame(int i);
        Texture* getFrame(int i);

        bool operator ==(Animation a);
        bool operator !=(Animation a) {if(*this==a) return false; return true;}

        virtual ~Animation();
    protected:
        vector<Texture> m_textures;
        int m_delay;
        Clock m_clock;
        bool m_running;
        int m_current;
    private:
};

#endif // ANIMATION_H
