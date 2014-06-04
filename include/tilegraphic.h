#ifndef TILEGRAPHIC_H
#define TILEGRAPHIC_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "animation.h"
using namespace std;
using namespace sf;



class TileGraphic
{
    public:
        TileGraphic(Animation a,ConvexShape c);
        TileGraphic();
        Animation* getAnimation(){return &m_animation;}
        ConvexShape* getConvexShape(){return &m_convexShape;}

        void setAnimation(Animation a){m_animation=a;}
        void setConvexShape(ConvexShape cs){m_convexShape=cs;}
        virtual ~TileGraphic();
    protected:
        ConvexShape m_convexShape;
        Animation m_animation;
    private:
};

#endif // TILEGRAPHIC_H
